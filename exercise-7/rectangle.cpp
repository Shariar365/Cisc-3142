#include <iostream>
#include<cmath>
using namespace std;
class Rectangle
{
	private:
		float length;
		float width;
	public:
		void setlength(float);
		void setwidth(float);
		float perimeter();
		float area();
		void show();
		int sameArea(Rectangle);
};
void Rectangle::setlength(float l)
{
	length = l;
}
void Rectangle::setwidth(float w)
{
	width = w;
}
float Rectangle::perimeter()
{
	return 2*(length + width);
}
float Rectangle::area()
{
	return length * width;
}
void Rectangle::show()
{
	cout << "Length: " << length << ", Width: " << width;
}
int Rectangle::sameArea(Rectangle second)
{
	float area1 = length * width;
	float area2 = second.length * second.width;
	if (area1 == area2)
		return 1;
	else	 
	return 0;
}
int main()
{
	Rectangle first;
	first.setlength(5);
	first.setwidth(2.5);
	
	Rectangle second;
	second.setlength(5);
	second.setwidth(18.9);
	
	cout << "First rectangle: ";
	first.show();
	cout << endl << "First rectangle Area: " << first.area() << ", First rectangle Perimeter:  " 
	<< first.perimeter() << endl << endl;
	
	cout << "Second rectangle: ";
	second.show();
	cout << endl << "Second rectangle Area: " << second.area() << ", Second rectangle Perimeter:  " 
	<< second.perimeter() << endl << endl;
	
	if (first.sameArea(second))
		cout << "Rectangles have the same area\n";
	else
		cout << "Rectangles do not have the same area\n\n";
		
	first.setlength(15);
	first.setwidth(6.3);
	cout << "First rectangle: ";
	first.show();
	cout << endl << "First rectangle Area: " << first.area() << ", First rectangle Perimeter:  "<< 
	first.perimeter() << endl << endl;
	cout << "Second rectangle: ";
	second.show();
	cout << endl << "Second rectangle Area: " << second.area() << ", Second rectangle Perimeter:  "<< 
	second.perimeter() << endl << endl;
	if (first.sameArea(second))
		cout << "Rectangles have the same area\n";
	else
		cout << "Rectangles do not have the same area\n";
	return 0;
}