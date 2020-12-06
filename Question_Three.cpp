#include <iostream>

int main()
{ 
   
    //definations
    std::size_t n{};
    
 
    //input
    std::cout << "PLEASE ENTER ORDER OF SQUARE MATRIX";
    std::cin >> n;
    std::cout<<"PLEASE ENTER VALUES FOR FIRST MATRIX ROW WISE, FROM LEFT TO RIGHT:";
    //creating pointer to array of pointer
    int** a{ new int* [n] };
    //assigning array to pointer
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    //asigning values to a
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            std::cin>>a[i][j];
    std::cout<<"PLEASE ENTER VALUES FOR SECOND MATRIX ROW WISE, FROM LEFT TO RIGHT:";
        //creating pointer to array of pointer
        int** b{ new int* [n] };
    //assigning array to pointer
        for (int i = 0; i < n; i++)
            b[i] = new int[n];
    //assigning valuse to b
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            std::cin>>b[i][j];    
        //creating pointer to array of pointer
        int** c{ new int* [n] };
    //assigning array to pointer
        for (int i = 0; i < n; i++)
            c[i] = new int[n];

   

    

    //MATRIX MULTIPLICATION
        
    // c[i][j]= sum of n times over iterative k a[i][k]*b[k][j]

    int sum{ 0 };

    for (int i{0};i < n;i++)
    {
         for (int j{0};j < n;j++)
        {
            
             for (int k{0};k < n;k++)
            {
                sum += ((a[i][k]) * (b[k][j]));
                
            }
            c[i][j] = sum;

        }
        
    }
   

    //printing matrice
    std::cout<<"A X B = \n";
    for (int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
            std::cout<<c[i][j]<<" "; 
        std::cout<<"\n";
          
     }
     // deallocate memory using delete[] operator
    for (int i = 0; i < n; i++)
        {delete[] a[i];}
 
        delete[] a;

    for (int i = 0; i < n; i++)
       { delete[] b[i];}
 
    delete[] b;

    // deallocate memory using delete[] operator
     for (int i = 0; i < n; i++)
       { delete[] c[i];}
 
    delete[] c;
    
    return 0;
}