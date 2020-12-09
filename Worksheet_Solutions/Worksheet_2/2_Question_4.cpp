#include <iostream>

int** mat_mult(int** a,int* a_size,int** b,int* b_size)
{
    //create new matrice
     //creating new matrice to hold array 
    int** c = { new int* [b_size[1]] };
    //assigning array to pointer
    for (int i = 0; i < b_size[1]; i++)
        c[i] = new int[a_size[0]];
    //initialize to 0
        for (int i=0;i<b_size[1];i++)
            for(int j=0;j<a_size[0];j++)
                c[i][j]=0;


      int sum{ 0 };
    for(int i=0;i<a_size[0];i++)
        for(int j=0;j<b_size[1];j++)
            {for(int k=0;k<b_size[0];k++)
                sum += a[k][i]*b[j][k];
            c[j][i]=sum;
            sum=0;
            }
    
return c;
}
int** mat_trans(int** a,int* a_size)
{   
    //creating new matrice to hold array 
    int** c = { new int* [a_size[0]] };
    //assigning array to pointer
    for (int i = 0; i < a_size[0]; i++)
        c[i] = new int[a_size[1]];
    //transpose
    for(int i=0;i<a_size[0];i++)
        for(int j=0;j<a_size[1];j++)
                c[i][j]=a[j][i];
    return c;

}

void mat_print(int** a,int* a_size)
{   
    std::cout<<"\n";
     for (int j=0;j<a_size[0];j++)
        {   for(int i=0;i<a_size[1];i++)
                std::cout<<a[i][j]<<" "; 
            std::cout<<"\n";
            
        }
    
}

int main()
{   
     //definations
    int n{}, m{}, n1{} , p{};
    
 
    //input
    std::cout << "PLEASE ENTER ROWS IN FIRST MATRIX";
    std::cin >> m;
    std::cout << "PLEASE ENTER COLUMNS IN FIRST MATRIX";
    std::cin >> n;
    std::cout << "PLEASE ENTER ROWS IN SECOND MATRIX";
    std::cin >> n1;
    std::cout << "PLEASE ENTER COLUMNS IN SECOND MATRIX";
    std::cin >> p;
    
    if(n!=n1)
    {
        std::cout<<"Enter matrices which can be multiplied.";
    }
    else
    {

    int a_size[2]={m,n};
    int b_size[2]={n,p};
    
    //creating pointer to array of pointer
    int** a{ new int* [a_size[1]] };
    //assigning array to pointer
    for (int i = 0; i < a_size[1]; i++)
        a[i] = new int[a_size[0]];
    std::cout<<"PLEASE ENTER VALUES FOR FIRST MATRIX ( "<<m<<"X"<<n<<" ) ROW WISE, FROM LEFT TO RIGHT:";
    //asigning values to a
    for (int j=0;j<m;j++)
        for (int i=0;i<n;i++)
            std::cin>>a[i][j];

    std::cout<<"A= \n";
                //print a
    for (int j=0;j<m;j++)
        {   for(int i=0;i<n;i++)
                std::cout<<a[i][j]<<" "; 
            std::cout<<"\n";
            
        }
 


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
    std::cout<<"B= \n";
    //print b
    for (int j=0;j<n;j++)
        {   for(int i=0;i<m;i++)
                std::cout<<b[i][j]<<" "; 
            std::cout<<"\n";
            
        }
    
   
    
   


    
    
   // (A.B)'= B'.A'
   // mat_trans(mat_mult(a,a_size,b_size,c),......) doesnt work

    //lhs 

    int** result{mat_mult(a,a_size,b,b_size)};//(A.B)
    int result_size[2]{a_size[0],b_size[1]};
    int** lhs{mat_trans(result,result_size)};//(A.B)'
    int lhs_size[2]{result_size[1],result_size[0]};
    std::cout<<"LHS:";
    mat_print(lhs,lhs_size);

    //rhs

    int** at{mat_trans(a,a_size)};//A'
    int at_size[2]{a_size[1],a_size[0]};
    int** bt{mat_trans(b,b_size)};//B'
    int bt_size[2]{b_size[1],b_size[0]};
    int** rhs{mat_mult(bt,bt_size,at,at_size)};//(B'.A')
    int rhs_size[2]{bt_size[0],at_size[1]};
    std::cout<<"RHS:";
    mat_print(rhs,rhs_size);
    int sum{0};
    for (int j=0;j<rhs_size[0];j++)
           for(int i=0;i<rhs_size[1];i++)
               sum += rhs[i][j]-lhs[i][j]; 
    if(sum==0)
        std::cout<<"Hence, The Identity (A.B)' = A'.B'is true! ";
    else
        std::cout<<"Fix ur program lol";


    
    //deleting allocated memory
        for (int i = 0; i < a_size[1]; i++)
            {delete[] a[i];}
    
            delete[] a;

        for (int i = 0; i < b_size[1]; i++)
        { delete[] b[i];}
    
            delete[] b;  
        for (int i = 0; i < result_size[1]; i++)
        { delete[] result[i];}
    
            delete[] result;  
        for (int i = 0; i < lhs_size[1]; i++)
        { delete[] lhs[i];}
    
            delete[] lhs;  
        for (int i = 0; i < at_size[1]; i++)
        { delete[] at[i];}
    
            delete[] at;  
        for (int i = 0; i < bt_size[1]; i++)
        { delete[] bt[i];}
    
            delete[] bt;
        for (int i = 0; i < rhs_size[1]; i++)
        { delete[] rhs[i];}
    
            delete[] rhs;    
        
    }
return 0;
}