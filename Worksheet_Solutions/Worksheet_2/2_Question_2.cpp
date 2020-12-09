/*
Write a function to find the length of a string using pointers.
*/

#include <iostream>
#include <cstring>

int length(const char* x)
{
    int i{0};
    while(*x!='\0')
    {
        x=x+1;
        i++;
    }
    return i;
}
int main()
{   
    
    std::string a;
    std::cout<<"Enter String:";
    std::cin>>a;
    const char* b = a.c_str();
    std::cout<<"Length of string is "<<length(b)<<".";
    return 0;
    
}