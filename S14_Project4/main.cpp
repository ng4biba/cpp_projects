//
//  main.cpp
//  Project 4 Spring 14
//
//  Created by Ibrahima Niang on 5/7/14.
//  Copyright (c) 2014 Ibrahima Niang. All rights reserved.
//

#include "stack.h"
#include "stack.cpp"


// take a character as an argument and check if it's an operator(+, -, /, *)
bool isOperators(char);

// take a character as an argument and check if it's an operands(0, 1, 2, 3 ...9)
bool isOperands(char);

// take a character as an argument and determine the order of operation using precedence of the operators
int order(char);

// take two characters as arguments and determine which one have the higher priority
bool isHigher(char, char);

// take two integer arguments as operands and one character as operator, calculate the expression and return it
int operation(int, int, char);

// take an infix expression, evaluate it and return it
int evaluateInfix(char expr);






int main()
{
    char str;       // variable to hold the expression characters
    int result;     // variable to hold the result;
    cout<<"\t Enter a well-formed expression. The expression may include parenthesis or space : \n\n";
    cout<<"\t Exemple: 2*6-356+2*(6/(4-2)) \n\n";
    cin>>str;
    
    result=evaluateInfix(str);
    cout<<"The result is :\t"<<result<<endl;;
    

    
    return 0;
    
}













//*********************** Method isOperators ********************
bool isOperators(char ch)
{
    if(ch=='-' || ch=='+' || ch=='*' || ch=='/')
        return true;
    else return false;
}

//*********************** Method isOperands ********************
bool isOperands(char ch)
{
    if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7'|| ch=='8' || ch=='9' )
        return true;
    else return false;
}

//*********************** Method order ********************
int order(char ch)
{
    switch (ch)
    {
        case '+': return (1);
        case '-': return (1);
        case '*': return (2);
        case '/': return (2);
        case '(': return (0);
            
        default:  return 1 ;
    }
}

//*********************** Method isHigher ********************
bool isHigher(char a, char b)
{
    if(order(a)>=order(b))
        return true;
    else
        return false;
    
}

//*********************** Method operation ********************
int operation(int a, int b, char ch)
{
    switch (ch)
    {
        case '+':
            return (a+b);
        case '-':
            return (a-b);
        case '*':
            return (a*b);
        case '/':
            return (a/b);
            
        default:  return 0;
            
    }
    
}

//*********************** Method evaluateInfix ********************
int evaluateInfix(char expression)
{
    char ch;
    string temp;
    int numb;
    int op1, op2;
    
    stack<char> stackOperators(10);
    stack<int> stackOperands(10);
    
    while(expression != '\n')
    {
        
        while(isOperands(expression) )
        {
            temp += expression;
            cin.get(expression);
        }
        
        istringstream convert(temp);
        if ( !(convert >> numb) )
            numb = 0;
        temp="";
        
        
        if(numb!=0)
            stackOperands.push(numb);
        
        if(isOperators(expression))
        {
            
            if((!(stackOperators.isEmpty()) && isHigher(stackOperators.top(), expression)))
            {
                ch=stackOperators.top();
                stackOperators.pop();
                op1=stackOperands.top();
                stackOperands.pop();
                op2=stackOperands.top();
                stackOperands.pop();
                stackOperands.push(operation(op2, op1, ch));
                if(!(stackOperators.isEmpty()) && isHigher(stackOperators.top(), expression))
                {
                    ch=stackOperators.top();
                    stackOperators.pop();
                    stackOperators.push(expression);
                    op1=stackOperands.top();
                    stackOperands.pop();
                    op2=stackOperands.top();
                    stackOperands.pop();
                    stackOperands.push(operation(op2, op1, ch));
                }
                else
                    stackOperators.push(expression);
            }
            
            
            else
                stackOperators.push(expression);
        }
        else if(expression=='(')
            stackOperators.push(expression);
        else if(expression==')')
        {
            while(!(stackOperators.top()=='('))
            {
                ch=stackOperators.top();
                stackOperators.pop();
                op1=stackOperands.top();
                stackOperands.pop();
                op2=stackOperands.top();
                stackOperands.pop();
                stackOperands.push(operation(op2, op1, ch));
            }
            stackOperators.pop();
            
        }
        
        if(expression!='\n')
            cin.get(expression);
        
        
    }
    while(!(stackOperators.isEmpty()))
    {
        ch=stackOperators.top();
        stackOperators.pop();
        op1=stackOperands.top();
        stackOperands.pop();
        op2=stackOperands.top();
        stackOperands.pop();
        stackOperands.push(operation(op2, op1, ch));
    }
    
    return stackOperands.top();
    
}