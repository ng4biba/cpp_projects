//
//  main.cpp
//  Project 1 Spring 14
//
//  Created by Ibrahima Niang on 2/3/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "fraction.h"

int main()
{
    
    fraction f1,f2(15,12),f3;
     cout << "Enter the first fraction in the form a/b: "<<endl;
     cin>>f1;
     f1=f1.reduce_fraction(f1);
     cout<<"Fraction 1 = ";
     cout<<f1<<endl;
     cout<<"Fraction 2 = ";
     cout<<f2<<endl;
    
     f3=f1+f2;
     cout<<f1<<" + "<<f2<<"= "<<f3<<endl;
    
     f3=f1-f2;
     cout<<f1<<" - "<<f2<<"= "<<f3<<endl;
    
     f3=f1/f2;
     cout<<f1<<" : "<<f2<<"= "<<f3<<endl;
    
     f3=f1*f2;
     cout<<f1<<" * "<<f2<<"= "<<f3<<endl;
    
     if(f1==f2)
     cout<<"Fraction 1 equals Fraction 2\n";
     else
     cout<<"Fraction 1 doesn't equal fraction 2\n";
    
     if(f1<f2)
     cout<<"Fraction 1 is less than Fraction 2\n";
     else
     cout<<"Fraction is greater than fraction 2\n";
    

    
    return 0;
}
