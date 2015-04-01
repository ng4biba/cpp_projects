//
//  stack.h
//  Project 4 Spring 14
//
//  Created by Ibrahima Niang on 5/7/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#ifndef Project_4_Spring_14_stack_h
#define Project_4_Spring_14_stack_h
#include <iostream>
#include <sstream>
using namespace std;

template<class xtype>
class stack
{
private:
    int length; // hold the length of the stack
    int max;    // maximum elements in the stack
    xtype *info;    // will hold the elements of the stack
public:
    stack(int);     // constructor intialize the stack to the maximum of elements
    ~stack();       // destructor to destroy the stack
    bool isFull();  // return true if the stack is full otherwise return false
    bool isEmpty(); // return true if the stack is empty otherwise return false
    void pop();     // delete the top element from the stack
    void push(xtype);   // add a new element to the stack
    void print();       // print the stack, need for debug
    xtype top();        // return the top elements of the stack
    
    
};

#endif
