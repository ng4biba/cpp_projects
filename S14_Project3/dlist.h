//
//  dlist.h
//  Project 3 Spring 14
//
//  Created by Ibrahima Niang on 4/18/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#ifndef __Project_3_Spring_14__dlist__
#define __Project_3_Spring_14__dlist__

#include <iostream>
using namespace std;

template <class xtype>
struct node
{
    xtype info;
    node *next;
    node *back;
};

template <class xtype>
class dlist
{
    private:
    node<xtype> *head; //head of the link list
    node<xtype> *last;  // tail of the likn list
    node<xtype> *temp;  // a pointer used to step through the list
    node<xtype> *current; // // another pointer used to step through the list needed for the LargeInt class
    int length;         //length of the list
    public:
    dlist(); // constructor
    ~dlist(); // destructor
    dlist ( const dlist<xtype> & other); //copy constructor
    dlist<xtype>& operator= ( const dlist<xtype> & other); ///assignment operator overloading
    void copyList( const dlist<xtype> & other); // copy function called by the copy constructor and the assignment operator overloading
    bool isFull();  // return true if the list is full else return false
    bool isEmpty(); // return true if the list is empty else return false
    void makeEmpty();   // function to destroy the list called by the destructor
    void insertFront ( xtype ); // insert a the front of the list
    void insertBack ( xtype );  // insert a the back of the list
    int getlength();        //return the length of the list
    xtype getCurrentInfo(); // return the data hold by *current
    xtype getTempInfo();    // return the data hold by *Temp
    void resetTempHead();   // will set *Temp to head if needed
    void resetTempLast();   // will set *Temp to last if needed
    void backIterator();    //iterator-based interface for the user from back to front using temp
    void frontIterator();   //iterator-based interface for the user from front to back using temp
    void resetCurrent();    // will set *Current to temp
    void currentBackIterator(); //iterator-based interface for the user from back to front using current
    void currentFrontIterator(); //iterator-based interface for the user from front to back using current
    void printList ();  // print the list
    void deleteItem(xtype); // delete item in the list
    bool searchItem(xtype); // look the item and return true if find else return true
};


#endif /* defined(__Project_3_Spring_14__dlist__) */
