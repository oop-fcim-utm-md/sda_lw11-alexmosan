#include "header.h"

#include <string>
#include <iostream>

static int index =0;
void initialize(node_t*& root, const char* string)
{
   
    if (string[index] == '(') 
    {
        root = new node_t;
        index++;
        initialize(root->left_, string);
    }
    if (string[index] == '+' || string[index] == '-' || string[index] == '*' || string[index] == '/') 
    {        
        root->value_ = string[index];
        index++;
        initialize(root->right_, string);
    }
    if (string[index] == ')') 
    {
        index++;
        return;
    }    
        root = new node_t;
        root->value_ = string[index];   
        index++;
}
void print(node_t* root)
{
    if (!root)
        return;
    print(root->left_);
    std::cout << root->value_ << std::endl;
    print(root->right_);
    
}

double evaluate(node_t* root)
{
    double a, b;
    if (!root->left_) 
        return std::stod(root->value_); 
    a = evaluate(root->left_); 
    b = evaluate(root->right_);
    switch (root->value_.c_str()[0]) { 
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0; 
}
void clear(node_t* root)
{
    if (root)
    {
        clear(root->left_);
        clear(root->right_);
        delete root;
    }    
}