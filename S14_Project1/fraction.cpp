//
//  fraction.cpp
//  Project 1 Srping 14
//  CSC 330-001
//  Created by Ibrahima Niang on 2/3/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "fraction.h"


//default constructor
fraction::fraction()
{
    num=NULL;
    denum=NULL;
}

//constructor
fraction::fraction(int c, int d)
{
    int a=c;
    int b= d;
    
    assert (d!=0);
    int gcd;
    int remainder;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
        
    }
    do
    {
        remainder=a%b;
        a=b;
        gcd=b;
        b=remainder;
    } while (remainder>0);
    num=c/gcd;
    denum=d/gcd;
    
}
// return the fraction in a reduced form
fraction fraction::reduce_fraction(fraction f)
{
    fraction temp;
    int a=f.num;
    int b= f.denum;
    
    int gcd;
    int remainder;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
        
    }
    do
    {
        remainder=a%b;
        a=b;
        gcd=b;
        b=remainder;
    } while (remainder>0);
    temp.num=f.num/gcd;
    temp.denum=f.denum/gcd;
    
    return temp;
    
    
}

//input overloading
istream& operator>>(istream& file, fraction &f)
{
    char slash;
    file>>f.num>>slash>>f.denum;
    return file;
}

//output overloading
ostream& operator<<(ostream& ofile, fraction &f)
{
    ofile<<f.num<<"/"<<f.denum;
    return ofile;
}

//addition operator overloading
fraction fraction::operator+(fraction f)
{
    fraction temp;
    temp.num=num*f.denum+denum*f.num;
    temp.denum=denum*f.denum;
    return reduce_fraction(temp);       //return a fraction in a reduce form
    
}

//sustraction overloading
fraction fraction::operator-(fraction f)
{
    fraction temp;
    temp.num=num*f.denum-denum*f.num;
    temp.denum=denum*f.denum;
    return reduce_fraction(temp);       //return a fraction in a reduce form
}

//division overloading
fraction fraction::operator/(fraction f)
{
    fraction temp;
    temp.num=num*f.denum;
    temp.denum=denum*f.num;
    return reduce_fraction(temp);       //return a fraction in a reduce form
}
fraction fraction::operator*(fraction f)
{
    fraction temp;
    temp.num=num*f.num;
    temp.denum=denum*f.denum;
    return reduce_fraction(temp);       //return a fraction in a reduce form
}

//equality comparison overloading
bool fraction::operator==(fraction f)
{
    if(num*f.denum==denum*f.num)
        return true;
    else return false;
}

//superiority or equal comparison overloading
bool fraction::operator>(fraction f)
{
    if(num*f.denum>denum*f.num)
        return true;
    else
        return false;
}
bool fraction::operator>=(fraction f)
{
    if(num*f.denum>=denum*f.num)
        return true;
    else
        return false;
}

//inferiority or equal comparison overloading
bool fraction::operator<(fraction f)
{
    if(num*f.denum<denum*f.num)
        return true;
    else
        return false;
}
bool fraction::operator<=(fraction f)
{
    if(num*f.denum<=denum*f.num)
        return true;
    else
        return false;
}

//not equal comparison overloading
bool fraction::operator!=(fraction f)
{
    if(num*f.denum!=denum*f.num)
        return true;
    else
        return false;
}

    
    

