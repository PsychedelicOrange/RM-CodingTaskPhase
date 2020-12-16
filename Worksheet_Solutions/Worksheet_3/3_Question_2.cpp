#include <iostream>
int binsearch(int* x, int n, int st,int r ,int l=0)
{   
    int m;
    m=(l+r)/2;
        if(x[m]<st)
        {
            l=m+1;
        }
        else if(x[m]>st)
        {
            r=m-1;
        }
        else 
        {
            return m;
        }
        binsearch(x,n,st,r,l);
    }

void bsort(int* x,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                //swap j and j+1
                int temp;
                temp = x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
            
        }
    }

}


int main()
{
    std::cout<<"Please specify length of array";
    int n;
    std::cin>>n;
    std::cout<<"Enter array : ";
    int* x{new int[n]};
    for(int i{};i<n;i++)
    {
        std::cin>>x[i];
    }
    bsort(x,n);
    std::cout<<"Enter term to search for : ";
    int searchterm{};
    std::cin>>searchterm;
    std::cout<<searchterm<<" is on "<<binsearch(x,n,searchterm,n-1)<<" index.";
    delete[] x;
    return 0;

}