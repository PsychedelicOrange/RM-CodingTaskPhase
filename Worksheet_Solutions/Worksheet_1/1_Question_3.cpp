#include <iostream>
int main()
{
    int m,n;
    std::cout << "PLEASE ENTER ROWS IN MATRIX";
    std::cin >> m;
    std::cout << "PLEASE ENTER COLUMNS IN MATRIX";
    std::cin >> n;

     //creating pointer to array of pointer
    int** a{ new int* [n] };
    //assigning array to pointer
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    std::cout<<"PLEASE ENTER VALUES FOR MATRIX ( "<<m<<"X"<<n<<" ) ROW WISE, FROM LEFT TO RIGHT:";
    //asigning values to a
    for (int j=0;j<m;j++)
        for (int i=0;i<n;i++)
            std::cin>>a[i][j];
    int* icount = new int[n*m-1];
    int* jcount = new int[n*m-1];
    int ii{0};
    //processing
    for (int j=0;j<m;j++)
        for (int i=0;i<n;i++)
            if(a[i][j]==0)
                {
                    icount[ii]=i;
                    jcount[ii]=j;
                    ii++;
                }

    for(int i =0;i<ii;i++)
        for(int k=0;k<m;k++)
            a[icount[i]][k]=0;      
    for(int i =0;i<ii;i++)
        for(int k=0;k<m;k++)
            a[k][jcount[i]]=0;
    //print matrix
    for (int j=0;j<m;j++)
        {   for(int i=0;i<n;i++)
                std::cout<<a[i][j]<<" "; 
            std::cout<<"\n";
            
        }      
    for (int i = 0; i < n; i++)
        {delete[] a[i];}
 
    delete[] a;
    delete[] icount;
    delete[] jcount;
    return 0;

}
