//  main.cpp
//  Project 2 Spring 2014
//
//  Created by Ibrahima Niang on 2/25/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "LargeInt.h"

int main ()
{
    LargeInt  x, y, z;                                                  // declaration of LargeInt
    
    // y="10";        // initialisation of a LargeInt
    
    cout << "Enter X an integer of your choice : ";
    cin>>x;                                                             // getting the LargeInt from the user
    cout<<endl;
    cout << "Enter Y another integer of your choice : ";
    cin>>y;
    cout<<"X is :"<<x<<endl<<endl;
    cout<<"Y is :"<<y<<endl;
    
    if (x == y)                                                         // Compare the two LargeInt
    cout<<"\nThe two numbers entered are equal."<<endl;
    else
    cout<<"\n\nThe two numbers entered are different\n\n";
    
    z=x+y;                                                               // add the two LargeInt and return it to z
    
    cout<<"X+Y= "<<z<<endl;                                             // display z, the sum of x and y
    
    
    
    return 0;
    
}
