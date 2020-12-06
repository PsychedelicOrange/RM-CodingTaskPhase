#include <iostream>

int main()
{ 
   
    //definations
    std::size_t n{}, m{}, n1{} , p{};
    
 
    //input
    std::cout << "PLEASE ENTER ROWS IN FIRST MATRIX";
    std::cin >> m;
    std::cout << "PLEASE ENTER COLUMNS IN FIRST MATRIX";
    std::cin >> n;
    std::cout << "PLEASE ENTER ROWS IN SECOND MATRIX";
    std::cin >> n1;
    std::cout << "PLEASE ENTER COLUMNS IN SECOND MATRIX";
    std::cin >> p;
    

    if(n==n1)
    {

    
    //creating pointer to array of pointer
    int** a{ new int* [n] };
    //assigning array to pointer
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    std::cout<<"PLEASE ENTER VALUES FOR FIRST MATRIX ( "<<m<<"X"<<n<<" ) ROW WISE, FROM LEFT TO RIGHT:";
    //asigning values to a
    for (int j=0;j<m;j++)
        for (int i=0;i<n;i++)
            std::cin>>a[i][j];
 


    //creating pointer to array of pointer
    int** b{ new int* [p] };
    //assigning array to pointer
    for (int i = 0; i < p; i++)
        b[i] = new int[n1];
    std::cout<<"PLEASE ENTER VALUES FOR SECOND MATRIX ( "<<n<<"X"<<p<<" ) ROW WISE, FROM LEFT TO RIGHT:";
    //asigning values to b
     for (int j=0;j<n;j++)
        for (int i=0;i<p;i++)
            std::cin>>b[i][j];
     
    
    //creating pointer to array of pointer
    int** c{ new int* [p] };
    //assigning array to pointer
        for (int i = 0; i < p; i++)
            c[i] = new int[m];
    //initialize to 0
        for (int i=0;i<p;i++)
            for(int j=0;j<m;j++)
                c[i][j]=0;
   

    

    //MATRIX MULTIPLICATION
        
    // c[i][j]= sum of n times over iterative k a[i][k]*b[k][j]

    int sum{ 0 };
    for(int i=0;i<m;i++)
        for(int j=0;j<p;j++)
            {for(int k=0;k<n;k++)
                sum += a[k][i]*b[j][k];
            c[j][i]=sum;
            sum=0;
            }



    //printing result
    std::cout<<"A= \n";
                //print a
    for (int j=0;j<m;j++)
        {   for(int i=0;i<n;i++)
                std::cout<<a[i][j]<<" "; 
            std::cout<<"\n";
            
        }
    std::cout<<"B= \n";
    //print b
    for (int j=0;j<n;j++)
        {   for(int i=0;i<m;i++)
                std::cout<<b[i][j]<<" "; 
            std::cout<<"\n";
            
        }
    std::cout<<"A X B = \n";
    for (int j=0;j<m;j++)
    {   for(int i=0;i<p;i++)
            std::cout<<c[i][j]<<" "; 
        std::cout<<"\n";
          
     }
     // deallocate memory using delete[] operator
    for (int i = 0; i < n; i++)
        {delete[] a[i];}
 
        delete[] a;

    for (int i = 0; i < p; i++)
       { delete[] b[i];}
 
    delete[] b;

    // deallocate memory using delete[] operator
     for (int i = 0; i < p; i++)
       { delete[] c[i];}
 
    delete[] c;
    }
    else
    {
        std::cout<<"Please enter matrices which can be multiplied!";
    }
    
    return 0;
}
