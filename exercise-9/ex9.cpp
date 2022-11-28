#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
int main () {
    
  ifstream file ("weather.csv.txt");

  vector < string > mon;
  vector < int >temp;
  int col = 1;
  
  std::string str;

  std::getline (file, str);

  while (std::getline (file, str))  {
    std::istringstream s (str);
    std::string w;
    
    while (std::getline (s, w, ','))	{
        if (col > 1) {
	    temp.push_back (std::stoi (w));
	    col = 0;
	}
	else {
	    mon.push_back (w);
	}
	  col++;
	}
    }

  ofstream output ("result.txt");

  int sum = 0;

  for (int i = 0; i < temp.size (); i++)    {
      sum += temp[i];
    }

  double simpleAverage = sum / temp.size ();

  output << "Simple Average: " << simpleAverage << endl;
  output << "Month Temperature MovingAverage WeightedMovingAverage" << endl;

  int moving_sum = 0;
  vector < double >mov_Ave;

  for (int i = 0; i < temp.size () - 2; i++)   {
      for (int j = i; j < i + 3; j++)	{
          moving_sum += temp[j];
	}

      mov_Ave.push_back (moving_sum / 3.0);

      moving_sum = 0;
    }

  int weighted_sum = 0;
  vector < double >weighted_ave;

      for (int i = 0; i < temp.size () - 2; i++)  {
          for (int j = i; j < i + 3; j++)  {
	  weighted_sum += temp[j] * ((j + 1) - i);
	}

      weighted_ave.push_back (weighted_sum / 6.0);
      weighted_sum = 0;
    }
    
  for (int i = 0; i < temp.size (); i++)    {
      if (i < 2){

      output << mon[i] << "    " << temp[i] << endl;
      
      }
      else if (i >= 2 && i <= 4) {

      output << mon[i] << "    " << temp[i] << "         " <<
      mov_Ave[i - 2] << "        " <<
      weighted_ave[i - 2] << endl;

      }
      else if (i == 5)	{

      output << mon[i] << "    " << temp[i] << "         " <<
      mov_Ave[i - 2] << "             " <<
      weighted_ave[i - 2] << endl;

      }
      else if (i >= 6 && i <= 9) {

      output << mon[i] << "    " << temp[i] << "         " <<
      mov_Ave[i - 2] << "        " <<
      weighted_ave[i - 2] << endl;

      }
    }
}