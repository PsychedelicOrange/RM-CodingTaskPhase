#include <iostream>
int main()
{
    int x,y,sumx{0},sumy{0};
    std::cin>>x;
    std::cin>>y;
    for (int i=1;i<x;i++)
    {
        if(x%i==0)
        {
            sumx=sumx+i;
        }
    }
     
    for (int i=1;i<y;i++)
    {
        if(y%i==0)
        {
            sumy=sumy+i;
        }
    }  
    if(sumx==y&sumy==x)
    {
        std::cout<<"The numbers are amicable.";
    }
    else
    {
     std::cout<<"The numbers are not amicable.";
    }
    
    return 0;
}
