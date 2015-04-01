//
//  dlist.cpp
//  Project 3 Spring 14
//
//  Created by Ibrahima Niang on 4/18/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "dlist.h"


template <class xtype>
dlist<xtype> :: dlist()
{
    head = last=NULL;
    length=0;
}

template <class xtype>
dlist<xtype> :: ~dlist()
{
    makeEmpty();
}

template <class xtype>
void dlist<xtype> :: makeEmpty()
{
    
    node<xtype> *p;
    
    while ( head != NULL )
    {
        p = head;
        head = head->next;
        delete p;
    }
    length=0;
}

template <class xtype>
bool dlist<xtype> :: isEmpty()
{
    return head == NULL;
}

template <class xtype>
bool dlist<xtype> :: isFull()
{
    node<xtype> *p = new node<xtype>;
    
    if ( p == NULL )
    return true;
    else{
        delete p;
        return false;
    }
}

template <class xtype>
dlist<xtype> :: dlist ( const dlist<xtype> & other )
{
    head = NULL;
    copyList (other);
}

template <class xtype>
dlist<xtype>& dlist<xtype>:: operator= ( const dlist<xtype> & other )
{
    copyList (other);
    return *this;
}

template <class xtype>
void dlist<xtype>:: copyList ( const dlist<xtype> & other )
{
    node<xtype> *temp;
    node<xtype> *p;
    
    if ( head != NULL )
    makeEmpty();
    
    if ( other.head == NULL )
    head = NULL;
    else
    {
        length=other.length;
        p = other.head;
        head = new node<xtype>;
        
        head->info = p->info;
        head->next = head->back = NULL;
        
        temp = head;
        p = p->next;
        
        while ( p != NULL )
        {
            temp->next = new node<xtype>;
            temp->next->info = p->info;
            temp->next->next = NULL;
            temp->next->back = temp;
            temp = temp->next;
            p = p->next;
        }
        last=temp;
    }
}

template <class xtype>
void dlist<xtype> :: printList()
{
    if ( head == NULL )
    cout<<"LIST IS EMPTY";
    else
    {
        node<xtype> *p = head;
        
        while ( p != NULL )
        {
            cout<<p->info<<"  ";
            p = p->next;
        }
        cout<<endl<<getlength()<<endl;
        p=last;
        while ( p != NULL )
        {
            cout<<p->info<<"  ";
            p = p->back;
        }
    }
}


template <class xtype>
void dlist<xtype>::insertFront(xtype item)
{
    if ( isFull() )
    cout<<"\nLIST IS FULL";
    else
    {
        node<xtype> *temp = new node<xtype>;
        temp->info = item;
        
        temp->next = head;
        temp->back = NULL;
        if (  head != NULL )
        head->back = temp;
        if(last==NULL)
        last=head;
        head = temp;
        length++;
    }
}
template <class xtype>
void dlist<xtype> :: insertBack( xtype item )
{
    if ( isFull() )
    cout<<"\nLIST IS FULL";
    else
    {
        node<xtype> *temp = new node<xtype>;
        temp->info = item;
        
        if ( head == NULL )
        {
            temp->next =temp->back = NULL;
            head=last=temp;
        }
        else
        {
            node<xtype> *p = head;
            
            while ( p->next != NULL)
            p = p->next;
            
            temp->next = NULL;
            p->next=temp;
            temp->back = p;
            last=temp;
        }
        length++;
    }
    
}

template <class xtype>
bool dlist<xtype> :: searchItem( xtype item )
{
    if ( head == NULL )
    cout<<"LIST IS EMPTY";
    else
    {
        node<xtype> *p = head;
        
        while ( p != NULL && p->info <= item )
        {
            if ( p->info == item )
            return true;
            p = p->next;
        }
    }
    return false;
}

template <class xtype>
void dlist<xtype> :: deleteItem( xtype item )
{
    if ( head == NULL )
    cout<<"\nLIST IS EMPTY";
    else
    {
        node<xtype> * r = head;
        
        if ( head->info == item )
        {
            delete r;
            head = head->next;
            length--;
        }
        else
        {
            while ( r != NULL  && r->info < item )
            r = r->next;
            
            if ( r != NULL && r->info == item )
            {
                r->back->next = r->next;
                if ( r->next != NULL )
                r->next->back = r->back;
                if(r->next==NULL)
                last=r->back;
                delete r;
                length--;
            }
            else  cout <<"\nITEM NOT IN THE LIST";
        }
    }
}

template <class xtype>
int dlist<xtype>::getlength()
{
    return length;
}

template <class xtype>
void dlist<xtype>::frontIterator()
{
    temp=temp->next;
}
template <class xtype>
xtype dlist<xtype> ::getTempInfo()
{
    return temp->info;
}
template <class xtype>
xtype dlist<xtype> ::getCurrentInfo()
{
    return current->info;
}
template <class xtype>
void dlist<xtype>::resetTempHead()
{
    temp=head;
}

template <class xtype>
void dlist<xtype>::backIterator()
{
    temp=temp->back;
}
template <class xtype>
void dlist<xtype>::resetTempLast()
{
    temp=last;
}
template <class xtype>
void dlist<xtype>::resetCurrent()
{
    current=temp;
}

template <class xtype>
void dlist<xtype>::currentBackIterator()
{
    current=current->back;
}
template <class xtype>
void dlist<xtype>::currentFrontIterator()
{
    current=current->next;
}
