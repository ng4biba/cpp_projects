//
//  fraction.h
//  Project 1 Srping 14
//
//  Created by Ibrahima Niang on 2/3/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#ifndef Project_1_Srping_14_fraction_h
#define Project_1_Srping_14_fraction_h

#include <iostream>
#include <assert.h>
using namespace std;

class fraction
{
    friend ostream& operator<<(ostream& ofile, fraction &a);
    friend istream& operator>>(istream& file, fraction &a);
private:
    int num;
    int denum;
public:
    fraction(int, int);
    fraction();
    
    fraction reduce_fraction(fraction);
    fraction operator+(fraction );
    fraction operator-(fraction );
    fraction operator/(fraction );
    fraction operator*(fraction );
    bool operator==(fraction);
    bool operator>(fraction);
    bool operator>=(fraction);
    bool operator<(fraction);
    bool operator<=(fraction);
    bool operator!=(fraction);
    
    
    
    
};





#endif
