//
//  stack.cpp
//  Project 4 Spring 14
//
//  Created by Ibrahima Niang on 5/7/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "stack.h"
#include <assert.h>
template <class xtype>
stack<xtype>::stack(int m)
{
    length=-1;
    max=m;
    info=new xtype [max];
}

template <class xtype>
stack<xtype>::~stack()
{
    delete [] info;
}

template <class xtype>
bool stack<xtype>::isFull()
{
    return (length+1)==max;
}

template <class xtype>
bool stack<xtype>::isEmpty()
{
    return (length==-1);
}

template <class xtype>
void stack <xtype>::pop()
{
    if(!isEmpty())
        length--;
}

template <class xtype>
void stack<xtype>::push(xtype item)
{
    if (!isFull())
        info[++length]=item;
}

template <class xtype>
xtype stack<xtype>::top()
{
    assert(!isEmpty());
        return info[length];
}
template <class xtype>
void stack<xtype>::print()
{
    for(int i=0;i<=length;i++)
    {
        cout<<info[i]<<" ";
    }
}
