#include <iostream>
using namespace std;
int main(){  
        float lethal_dose, weight, goal, total_soda;
        float total_amount;
	float soda_sweetner = 0.001;
	float soda_weight= 12.0;

	cout << "How much was the lethal amount?: ";
	cin >> lethal_dose;

	cout << "How much did the mouse weigh?: ";
	cin >> weight;

	cout << "What is your weight (in pounds)?: ";
	cin >> goal;
	
	float num_soda = lethal_dose / weight;
	total_amount = (goal * num_soda);
	total_soda = soda_sweetner * soda_weight;
	cout << "You can drink " << (total_amount/total_soda) << " cans of soda without dying." << endl;

	return 0;
}
		
       			