//Write a function to copy a string into another string using pointers.


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
void copy(char* y, const char* x)
{
    while(*x!='\0')
    {
        *y=*x;
        y++;x++;
    }

}
int main()
{   
    
    std::string a;
    std::cout<<"Enter String:";
    std::cin>>a;
    const char* a_ = a.c_str();
    char* b = new char[length(a_)];
    copy(b,a_);

    std::cout<<b;


    delete[] b;
    return 0;
    
    
}