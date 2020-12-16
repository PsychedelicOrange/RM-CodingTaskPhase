#include <iostream>
#include <cstring>

int sum(int* x,int n,int i=1)
{
    if(i<n)
    {
    x[0]+=x[i];
    i++;
    sum(x,n,i);
    }
    return x[0];
}
int main()
{
    std::string a;
    std::cout<<"Enter Number:";
    std::cin>>a;
    int length = a.length();
    int* b = new int[length];
    for(int i=0;i<length;i++)
        b[i]=a[i]-'0';
 //without recursion  
    int summation{0};
    for (int i=0; i<length; i++)
    { 
       summation = summation + b[i];
    }
    std::cout<<summation;
  //with recursion 
    std::cout<<"\n"<<sum(b, length);
  
    delete[] b;
    return 0;

}