#include <iostream>
#include <string>
int main()
{ 
    std::string x;
    std::cin>>x;
    int length{(int)x.length()};
    int* a= new int[length];
    for(int i=0;i<length;i++)
         a[i]= x[i]-'0';
    int k{0};
   int diff;
  int mult;
  bool isHill;
    for(int i=0;i<length-1;i++)
     {
      diff=a[i+1]-a[i];
        mult=diff*mult;
       if (diff<0&&k==0)
       {
           k=1;
           
       } 
       else if (diff>0&&k==1)
       {
           isHill=0;
       }

       
       
     } 
    delete[] a;
     if(mult<0&&isHill!=0)  
        std::cout<<"Is a hill number";
    else
    {
        std::cout<<"Not a hill number";
    }
    
    return 0;
}
