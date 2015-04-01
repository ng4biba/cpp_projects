//
//  LargeInt.h
//  Project 3 Spring 14
//
//  Created by Ibrahima Niang on 4/25/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#ifndef Project_3_Spring_14_LargeInt_h
#define Project_3_Spring_14_LargeInt_h

#include "dlist.h"
#include "dlist.cpp"

class LargeInt
{
    protected:
    long size;      // store the maximum size of the array for the LargeInt
    long length;    // store actual length of the large integer
    char sign;     // hold the sing of the num
    dlist<int> integer;   // pointer to hold the dynamic array
    
    public:
    friend ostream& operator<<(ostream&, LargeInt&);    // insertion operator overloading
    friend istream& operator>>(istream&, LargeInt&);    // extraction operator overloading
    LargeInt(int);  // constructor
    LargeInt();// default constructor
    void operator=(string);     // equal operator overloading for the LargeInt
    LargeInt operator+(LargeInt);   // addition operator overloading for the LargeInt
    LargeInt operator-(LargeInt);   // sustraction operator overloading for the LargeInt
    bool operator==(LargeInt);      // comparative operator overloading
    bool operator>(LargeInt);       // compare two LargeInt for only their absolute value
    void swap(LargeInt&, LargeInt&);    // swap two LargeInt needed if substracting from a smaller number
    
};


#endif
