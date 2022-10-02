/*Pseudocose:
#include <vector>
#include <iostream>
using namespace std;

int main(){  

    initializing a vector with 10 elements;

    int first_value = 1;
    first element in vector = first_value;
    print out first value;
    initialize iterator variable "it"
    for (it=vector(0)+1; it != vector(10) ;++it)  
    {
        it=(it)*2;

        cout<<it<<" ";
    }
    return 0;
} 
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){  

    vector<int> vec(10);
    int first_value = 1;
    *vec.begin() = first_value;

    cout<<*vec.begin()<<" ";
    std::vector<int>::iterator it;
    for (it=vec.begin()+1; it != vec.end() ;++it)
    {
        *it=*(it-1) * 2;

        cout<<*it<<" ";
    }

    return 0;
}