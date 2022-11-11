#include <iostream>
#include<cmath>
using namespace std;
class Sample
{
private:
    int x;
    double y;
public :
    Sample(); //Constructor 1
    Sample(int); //Constructor 2
    Sample(int, int); //Constructor 3
    Sample(int, double); //Constructor 4
};
Sample :: Sample()
{
    x = 0;
    y = 0;
}
Sample :: Sample(int i)
{
    x = i;
    y = 0;
}
Sample :: Sample(int i, int j)
{
    x = i;
    y = j;
}
Sample :: Sample(int i, double j)
{
    x = i;
    y = j;
}
int main()
{
}