#include <iostream>

void ssort(int* x,int n,int* y)
{
 unsigned int offset{ 0 };
    int lowest{ 0 };
    unsigned int i;
    
    while (offset < n)
    {
        i = offset;
        lowest = offset;
        while (i < n)
        {
            if ((int)x[offset] > (int)x[i])
                lowest = i;
            i++;
        }

        //swap

        char temp;
        temp = x[lowest];
        x[lowest] = x[offset];
        x[offset] = temp;
        offset++;
    }
    for(int i=0;i<n;i++)
    {
        y[i]=x[i];

    }


}
void bsort(int* x,int n,int* y)
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

    for(int i=0;i<n;i++)
    {
        y[i]=x[i];
    }
}
int search(int k,int* x,int n)
{   
   
   int l{0}, r{n-1},int m;
   while(l<=r)
   {
       m=(l+r)/2;
       if(x[m]<x[k])
       {
           l=m+1;
       }
       else if(x[m]>x[k])
       {
           r=m-1;
       }
       else
       {
           return m;
       }
        return -1;
   }

    

}
