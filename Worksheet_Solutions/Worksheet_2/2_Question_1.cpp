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
   
   int l{0}, r{n-1}, m;
   while(l<=r)
   {
       m=(l+r)/2;
       if(x[m]<k)
       {
           l=m+1;
       }
       else if(x[m]>k)
       {
           r=m-1;
       }
       else 
       {
           return m;
       }
       
        
   }

    return -1;

}

int main()
{
    //choice
    std::cout<<"Please specify length of array";
    int n;
    std::cin>>n;
    std::cout<<"Enter array to get sorted: ";
    int* x{new int[n]};
    for(int i{};i<n;i++)
    {
        std::cin>>x[i];
    }
    std::cout<<" which method to use: Type ‘s’ for Selection Sort and ‘b’ for Bubble Sort ; Then press Enter";
    char sortchoice;   
    std::cin>>sortchoice;
    int* result {new int[n]};
    if(sortchoice=='b')
    {
        bsort(x,n,result);
    }
    if(sortchoice=='s')
    {
        ssort(x,n,result);
    }
    else
    {
        std::cout<<"please enter valid character";
        return 0;
    }
    for(int i{};i<n;i++)
    {
        std::cout<<result[i];
    }
    
    delete[]x;


    std::cout<<"Please specify a entry you entered in array : ";
    int srch;
    std::cin>>srch;
    int searchresult{search(srch,result,n)};
    if(searchresult<0)
    {
        std::cout<<"number not in the array!";
    }
    else
    {
    std::cout<<"Your entry is present at "<<searchresult<<" index in the sorted array.";
    }
   
    delete[]result;
}