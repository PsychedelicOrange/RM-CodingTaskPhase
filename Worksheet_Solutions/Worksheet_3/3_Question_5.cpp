#include  <iostream>
int gcd(int x, int y)
{
    if(x>y)
    {
        x=x-y;
        gcd(x,y);
    }
    else if(x<y)
    {
        y=y-x;
        gcd(x,y);
    }
    else
    {
        return x;
    }
    
    
}
int main()
{   int x,y;
    std::cout<<"Enter Two Numbers : ";
    std::cin>>x>>y;
    std::cout<<gcd(x,y);
    return 0;
} 