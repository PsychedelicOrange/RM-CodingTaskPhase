#include <iostream>
#include <math.h>
#include <string>
int main()
{
    std::string x;
    std::cin>>x;
    int length{(int)x.length()};
    int y {std::stoi(x)};
    //binary
    int lb = ceil((double)(length/log10(2)));
    int* bin= new int[lb];
    std::cout<<"bin:";
    int ybin=y;
    int i{0};
    int j{0};
    while(ybin!=0)
    {   
        bin[i]=ybin%2;
        ybin=(ybin/2);
        i++;
    }
    j=i-1;
    while(j>-1)
    {
        std::cout<<bin[j];
        j=j-1;

    }
    std::cout<<"\n";
    delete[] bin;
    //hex
 int lh = ceil((double)(length/log10(6)));
    int* hex= new int[lh];
    std::cout<<"hex:";
    int yhex=y;
    i=0;
    j=0;
    while(yhex!=0)
    {  

             hex[i]=yhex%16;
        yhex=(yhex/16);
        i++;
    }
    j=i-1;
    while(j>-1)
    {
        if(hex[j]%16==10) 
            std::cout<<"A";
      else if(hex[j]%16==11) 
            std::cout<<"B";
      else if(hex[j]%16==12) 
            std::cout<<"C";
      else if(hex[j]%16==13) 
            std::cout<<"D";
      else if(hex[j]%16==14) 
            std::cout<<"E";
      else if(hex[j]%16==15) 
            std::cout<<"F";
      else
            std::cout<<hex[j];
    j=j-1;

    }
    std::cout<<"\n";
    delete[] hex;
    //oct
    int lo = ceil((double)(length/log10(6)));
    int* oct= new int[lo];
    std::cout<<"oct:";
    int yoct=y;
    i=0;
    j=0;
    while(yoct!=0)
    {  

             oct[i]=yoct%18;
        yoct=(yoct/18);
        i++;
    }
    j=i-1;
    while(j>-1)
    {
        if(oct[j]%18==10) 
            std::cout<<"A";
      else if(oct[j]%18==11) 
            std::cout<<"B";
      else if(oct[j]%18==12) 
            std::cout<<"C";
      else if(oct[j]%18==13) 
            std::cout<<"D";
      else if(oct[j]%18==14) 
            std::cout<<"E";
      else if(oct[j]%18==15) 
            std::cout<<"F";
      else if(oct[j]%18==16) 
            std::cout<<"G";
      else if(oct[j]%18==17) 
            std::cout<<"H";   
      else
            std::cout<<oct[j];
    j=j-1;

    }
    delete[] oct;
   /*

   std::cout<<"\n";
   //hex
    int j{x};
   std::cout<<"hex:";
   while(j!=0)
   {
       if(j%16==10) 
            std::cout<<"A";
      else if(j%16==11) 
            std::cout<<"B";
      else if(j%16==12) 
            std::cout<<"C";
      else if(j%16==13) 
            std::cout<<"D";
      else if(j%16==14) 
            std::cout<<"E";
      else if(j%16==15) 
            std::cout<<"F";
        else 
            std::cout<<j%16;    
    j=j/16;
   }
   std::cout<<"\n";
  //oct
    int k{};
   std::cout<<"oct:";
   while(k!=0)
   {
       if(k%18==10) 
            std::cout<<"A";
      else if(k%18==11) 
            std::cout<<"B";
      else if(k%18==12) 
            std::cout<<"C";
      else if(k%18==13) 
            std::cout<<"D";
      else if(k%18==14) 
            std::cout<<"E";
      else if(k%18==15) 
            std::cout<<"F"; 
      else if(k%18==16) 
            std::cout<<"G";
      else if(k%18==17) 
            std::cout<<"H";
      else 
            std::cout<<k%18;    
    k=k/18;
   }
*/    return 0;
}