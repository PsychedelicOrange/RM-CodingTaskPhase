/*
(a) Given a 2D character array, where each row is a string, write a
function which rearranges the strings in ascending order based on their
lengths.
 Input: word Output: cat
 number word
 cat number
(b) Also, sort each individual string in ascending order.
Output: act
 dorw
 bemnru
 */

#include <iostream>
#include <string>
void sortstring(std::string* x,int n,int* l)
{
     int i, j, imin;
   for(i = 0; i<n-1; i++) 
      {imin = i;   
             for(j = i+1; j<n; j++)
                {if(l[j] < l[imin])
                    imin = j;
                }
         
         (x[i]).swap( x[imin]);
      }
}
int main()
{   

    
    std::cout<<"please tell number of words: ";
    int nw;
    std::cin>>nw;
    std::cout<<"Enter "<<nw<<" words";
    std::string* a= new std::string[nw];
    int* length = new int[nw];
    for(int i=0;i<nw;i++)
    {
        std::cin>>a[i];
        

    }
    for(int i=0;i<nw;i++)
    {
       length[i]=a[i].length();
    }
    
    // sorting letters (b)
    for(int i=0;i<nw;i++)
    {
          unsigned int offset{ 0 };
    int lowest{ 0 };
    unsigned int j;
    while (offset < length[i])
    {
        j = offset;
        lowest = offset;
        while (j < length[i])
        {
            if ((int)a[i][offset] > (int)a[i][j])
                lowest = j;
            j++;
        }

        //swap

        char temp;
        temp = a[i][lowest];
        a[i][lowest] = a[i][offset];
        a[i][offset] = temp;
        offset++;
    }
   
    }
        //sorting strings
        sortstring(a,nw,length);

    for(int i=0;i<nw;i++)
    {
        std::cout<<length[i]<<" "<<a[i]<<"\n";
    }
    
  return 0;
}// 10 cat dog bufallo battledog catterpillar moth giraffe lemur edgar maya