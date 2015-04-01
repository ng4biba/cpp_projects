//
//  LargeInt.cpp
//  Project 3 Spring 14
//
//  Created by Ibrahima Niang on 4/25/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.

#include "LargeInt.h"

LargeInt::LargeInt()
{
    size =0;
    length=0;
}

istream& operator>>(istream& file, LargeInt &myInt)
{
    string temp;
    file>>temp;
    int boundary=0;
    myInt.size=temp.length();
    myInt.length=0;
    if (temp[0]=='-')
    {
        myInt.sign='-';
        boundary++;
    }
    
    else
    myInt.sign='+';
    for (long i=myInt.size-1; i>=boundary; i--)
    {
        
        myInt.integer.insertBack((temp[i]-'0'));
        myInt.length++;
    }
    return file;
}
ostream& operator<<(ostream& ofile, LargeInt &myInt)
{
    ofile<<myInt.sign;
    myInt.integer.resetTempLast();
    
    for (int i=myInt.integer.getlength(); i>0; i--)
    {
        ofile<<myInt.integer.getTempInfo();
        myInt.integer.backIterator();
    }
    return ofile;
    
}
void LargeInt::operator=(string temp)
{
    if (temp[0]=='-')
    sign='-';
    else
    sign='+';
    size=temp.length();
    length=0;
    for (long i=size-1; i>=0; i--)
    {
        integer.insertBack(temp[i]-'0');
        length++;
    }
}
bool LargeInt::operator==(LargeInt myInt)
{
    int index=0;
    bool flag=true;
    if (myInt.length!=length)
    return false;
    integer.resetTempHead();
    myInt.integer.resetTempHead();
    while (index<myInt.integer.getlength() && flag)
    {
        if (integer.getTempInfo()!=myInt.integer.getTempInfo())
        flag=false;
        index++;
        integer.frontIterator();
        myInt.integer.frontIterator();
    }
    return flag;
}

void LargeInt::swap(LargeInt & int1, LargeInt & int2)
{
    LargeInt temp;;
    int1.integer.resetTempHead();
    for (int i=0; i<int1.integer.getlength(); i++)
    {
        temp.integer.insertBack(int1.integer.getTempInfo());
        int1.integer.frontIterator();
    }
    int1.integer.makeEmpty();
    int2.integer.resetTempHead();
    for (int i=0; i<int2.integer.getlength(); i++)
    {
        int1.integer.insertBack(int2.integer.getTempInfo());
        int2.integer.frontIterator();
    }
    int2.integer.makeEmpty();
    temp.integer.resetTempHead();
    for (int i=0; i<temp.integer.getlength(); i++)
    {
        int2.integer.insertBack(temp.integer.getTempInfo());
        temp.integer.frontIterator();
    }
    
}

bool LargeInt::operator>(LargeInt myInt)
{
    
    int index=0;
    bool flag=false;
    if(integer.getlength()==myInt.integer.getlength())
    {
        integer.resetTempLast();
        myInt.integer.resetTempLast();
        while (index<myInt.integer.getlength() && !flag)
        {
            if (integer.getTempInfo()>myInt.integer.getTempInfo())
            {
                return true;
                break;
            }
            index++;
            integer.backIterator();
            myInt.integer.backIterator();
        }
    }
    
    return flag;
    
}

LargeInt LargeInt::operator+(LargeInt myInt)
{
    LargeInt sum;
    int diff;
    int carry=0;
    int borrow=0;
    int temp;
    
    if ((sign=='+' && myInt.sign=='+'))
    sum.sign='+';
    else if ((sign=='-' && myInt.sign=='-'))
    sum.sign='-';
    else if(integer.getlength()>myInt.integer.getlength())
    sum.sign=sign;
    else if (myInt.integer.getlength()>integer.getlength())
    sum.sign =myInt.sign;
    else
    {
        if(*this>myInt)
        sum.sign=sign;
        else
        sum.sign=myInt.sign;
        
    }
    
    
    if ((sign=='+' && myInt.sign=='+') || (sign=='-' && myInt.sign=='-'))
    {
        myInt.integer.resetTempHead();
        integer.resetTempHead();
        for (int i=0; i<integer.getlength() && i< myInt.integer.getlength();i++)
        {
            temp=(integer.getTempInfo()+myInt.integer.getTempInfo()+carry)%10;
            if (integer.getlength() == myInt.integer.getlength() && (i+1)==integer.getlength() && (integer.getTempInfo()+myInt.integer.getTempInfo())>9)
            {
                temp=(integer.getTempInfo()+myInt.integer.getTempInfo()+carry);
            }
            sum.integer.insertBack(temp);
            if (integer.getTempInfo()+myInt.integer.getTempInfo()+carry>9)
            carry=1;
            else
            carry=0;
            myInt.integer.frontIterator();
            integer.frontIterator();
            
        }
        
        if (integer.getlength()>myInt.integer.getlength())
        {
            integer.resetCurrent();
            diff=(integer.getlength()-myInt.integer.getlength());
            for (int i=0; i<diff; i++)
            {
                temp=(integer.getCurrentInfo()+carry)%10;
                if (i==(diff-1))
                temp=(integer.getCurrentInfo()+carry);
                sum.integer.insertBack(temp);
                if (integer.getCurrentInfo()+carry>9)
                carry=1;
                else
                carry=0;
                integer.currentFrontIterator();
            }
            
        }
        
        else
        {
            myInt.integer.resetCurrent();
            diff=(myInt.integer.getlength()-integer.getlength());
            for (int i=0; i<diff; i++)
            {
                temp=(myInt.integer.getCurrentInfo()+carry)%10;
                if (i==(diff-1))
                temp=(myInt.integer.getCurrentInfo()+carry);
                sum.integer.insertBack(temp);
                if (myInt.integer.getCurrentInfo()+carry>9)
                carry=1;
                else
                carry=0;
                myInt.integer.currentFrontIterator();
            }
        }
        
    }
    else
    {
        if(integer.getlength() < myInt.integer.getlength() || (myInt>*this))
        //if(!(*this>myInt))
            swap(*this, myInt);
        myInt.integer.resetTempHead();
        integer.resetTempHead();
        for (int i=0; i<integer.getlength() && i< myInt.integer.getlength();i++)
        {
            if (integer.getTempInfo()<myInt.integer.getTempInfo()+carry)
            {
                borrow=10;
            }
            else
            {
                borrow=0;
            }
            temp=((integer.getTempInfo()+borrow)-(myInt.integer.getTempInfo()+carry));
            if (integer.getTempInfo()<myInt.integer.getTempInfo()+carry)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            
            sum.integer.insertBack(temp);
            
            myInt.integer.frontIterator();
            integer.frontIterator();
            
        }
        
        if (integer.getlength()>myInt.integer.getlength())
        {
            integer.resetCurrent();
            diff=(integer.getlength()-myInt.integer.getlength());
            for (int i=0; i<diff; i++)
            {
                temp=((integer.getCurrentInfo()+borrow)-(carry))%10;
                sum.integer.insertBack(temp);
                
                if (integer.getCurrentInfo()<carry)
                {
                    borrow=10;
                    carry=1;
                }
                else
                {
                    borrow=0;
                    carry=0;
                }
                
                integer.currentFrontIterator();
            }
            
            
        }
        else
        {
            myInt.integer.resetCurrent();
            diff=(myInt.integer.getlength()-integer.getlength());
            for (int i=0; i<diff; i++)
            {
                temp=((myInt.integer.getCurrentInfo()+borrow)-(carry))%10;
                sum.integer.insertBack(temp);
                
                if (myInt.integer.getCurrentInfo()<carry)
                {
                    borrow=10;
                    carry=1;
                }
                else
                {
                    borrow=0;
                    carry=0;
                }
                
                myInt.integer.currentFrontIterator();
            }
        }
        
    }
    return sum;
}
