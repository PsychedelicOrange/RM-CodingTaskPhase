#include <iostream>
int main()
{

std::string x;
std::cin>>x;
int i{0};
int k{0};
bool isHill{1};
while( i<(x.length()))
{  if( x[i]>x[i+1] )
    {
        k=1;
    }
    else
    {
        if(k==1)
        {
            isHill=0;
        }
    }
    i++;
}
std::cout<<isHill;
return 0;


}