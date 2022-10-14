#include <iostream>
#include<cmath>
using namespace std;
int main()
{   cout << "Prime Numbers between 3 and 100 are:\n";

    for(int i=3;i<=100;++i) 
    {   int counter=0;

        for(int j=2;j<=sqrt(i);++j) 

        {   if(i%j==0)

                counter=1; //if number is not prime

        }

        if(counter==0) //numer is prime

                cout<<i<<" ";

    }

    return 0;

}