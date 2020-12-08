#include<iostream>
int main()
{ 
    //input

    std::string x;
    std::cin >> x;

    //sorted using selection sort

    unsigned int offset{ 0 };
    int lowest{ 0 };
    unsigned int i;
    unsigned int length{ x.length() };
    while (offset < length)
    {
        i = offset;
        lowest = offset;
        while (i < length)
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

    //output

    std::cout << x;
    return 0;
}
