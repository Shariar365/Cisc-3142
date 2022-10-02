#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int years; 
    int i;
    double cost;
    double rate; 
     
    cout << "Enter the number of years your item will be purchased: "; 
    cin >> years; 
    cout << "Enter the cost of your item: $"; 
    cin >> cost; 
    cout << "Enter the inflation rate: "; 
    cin >> rate;  
 
    rate = rate / 100;  
 
    for(i=0;i<years;i++)  
    cost = cost + cost*rate;  
 
    cout << "The cost of the item after " << years << " years will be $ " << cost << "."; 
     
    return 0; 
}