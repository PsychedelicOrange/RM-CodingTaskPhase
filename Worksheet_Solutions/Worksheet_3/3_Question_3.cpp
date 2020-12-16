#include <iostream>

int fact(int n)
{   
    if(n>1)
        n=fact(n-1)*n;
    return n;
}

int main()
{
    std::cout<<fact(10);
    return 0;
}