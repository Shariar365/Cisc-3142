/*pseudocose:
#include<iostream>
using namespace std;
int main()
{
  
 int n, i;
 float mean_X=0, mean_Y=0, a, b;

 //reading from file 
 if (tmpfile >> x >> " " >> y){
 for(i=1;i<=n;i++)
 {
  mean_X=mean_X+x[i]/n;
  mean_Y=mean_Y+Y[i]/n;

 b = (x[i]-mean_X)*(y[i]-mean_Y)/(x[i]-mean_X)*(x[i]-mean_X); //slope
 a = mean_Y - b*mean_X; //intercept
 l=a+b*x[i]; //Linear regression
}
}
 cout<<"Linear regression model is: y = "<< a <<" + "<< b<<"x";
 cout<<"Linear regression calculation is: y = "<< a <<" + "<< b<<"x";

 return(0);
}
*/
#include<iostream>
using namespace std;
int main()
{
  
 int n=3, i;
 float mean_X=0, mean_Y=0, a, b, l;

 //reading from file 
 int x[3]={2,3,1};
 int y[3]={2,3,1};
 for(i=1;i<=n;i++)
 {
  mean_X=mean_X+x[i]/n;
  mean_Y=mean_Y+y[i]/n;

 b = (x[i]-mean_X)*(y[i]-mean_Y)/(x[i]-mean_X)*(x[i]-mean_X); //slope
 a = mean_Y - b*mean_X; //intercept
 l=a+b*x[i]; //Linear regression
}
 cout<<"Linear regression model is: y = "<< a <<" + "<< b<<"x \n";
 cout<<"Linear regression calculation is: y = "<< l<<"x";
}