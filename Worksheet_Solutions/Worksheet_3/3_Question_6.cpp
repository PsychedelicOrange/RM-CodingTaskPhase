#include <iostream>

int bsort(int* x,int n,int j=0)
{
    for(int i=0;i<n-1;i++)
    {
        if(x[i]>x[i+1])
        {
            //swap
            int temp =x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
        }
    }
    if(j=n-1)
    {
        return 0;
    }
    else
    {
       j++;
       bsort(x,n,j);
    }
}
int main()
{
 std::cout<<"enter number of entries: ";
 int n;
 std::cin>>n;
 std::cout<<"please enter "<<n<<" numbers : ";
 int* nums = new int[n];
  for(int i=0;i<n;i++)
    {
      std::cin>>nums[i];  
    }
 bsort(nums,n);
 std::cout<<"\n";
 for(int i=0;i<n;i++)
    {
    std::cout<<nums[i]<<" ";
    }
    delete[] nums;
    return 0;
}