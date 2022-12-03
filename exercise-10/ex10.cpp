#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>     
#include <algorithm>     

using namespace std;

struct Subject {
  string subject;
  Subject(string s){
    subject = s;
  }
};

struct Actor {
  string actor;
  Actor(string s){
    actor = s;
  }
};

struct Actress {
  string actress;
  Actress(string s){
    actress = s;
  }
};

struct Director {
  string director;
  Director(string s){
    director = s;
  }
};

struct Movie {
  int year;
  int length;
  string title;
  Subject subject = Subject("");
  Actor actor = Actor("");
  Actress actress = Actress("");
  Director director = Director("");
  int popularity;
  bool award;
  string image;
  bool operator< (const Movie &other) const {
    return popularity > other.popularity;
  }
};

vector<string> Str(string str, char c){
  vector<string> mv;
  string s = "";
  for (auto m : str){
    if (m == c){
      mv.push_back(s);
      s = "";
    }
    else {
      s = s + m;
    }
  }
  mv.push_back(s);
  return mv;
}

Movie data(vector<string> data){
  Movie movie;
  movie.year = data[0] == "" ? 0 : stoi(data[0]);
  movie.length = data[1] == "" ? 0 :stoi(data[1]);
  movie.title = data[2];
  movie.subject = Subject(data[3]);
  movie.actor = Actor(data[4]);
  movie.actress = Actress(data[5]);
  movie.director = Director(data[6]);
  movie.popularity = data[7] == "" ? 0 :stoi(data[7]);
  movie.award = ( data[8] == "No" ? false : true );
  movie.image = data[9];
  return movie;
}
int accumulate(vector<Movie> movies, int n){

  int lengths[n];
  int i = 0;
  for (auto s: movies){
    lengths[i] = s.length;
    i++;
  }
  int count  = 0;
  int totalLength = accumulate(lengths,lengths+n,count);
  return totalLength;
}

vector<Movie> sort(vector<Movie> movies){
  vector<Movie> m = movies;
  sort(m.begin(), m.end());
  return m;
}

string find_data(vector<Movie> movies, string name){
  for(auto s : movies){
    string directorName = s.director.director;

    if (!directorName.find(name)){
      return directorName;
    }
  }
  return "No result found";
}

vector<vector<int>> Unique(vector<Movie> movies, string action, string comedy){

  vector<vector<int> > unique_year;
  vector<int> a;
  vector<int> b;

  for (auto s : movies){
    if (s.subject.subject == action)
      a.push_back(s.year);
    else if (s.subject.subject == comedy)
      b.push_back(s.year);
  }

  unique_year.push_back(a);
  unique_year.push_back(b);

  return unique_year;
}

bool equalYear(vector<int> years1, vector<int> years2){
  int* y1 = &years1[0]; 
  return (equal(years2.begin(), years2.end(), y1));
}

int main() {
  int cols = 10;
  ifstream file ("film.csv.txt");
  ofstream output ("result.txt"); 
  string str = "";
  getline(file, str);
  getline(file, str);
  vector<string> strs;
  vector<Movie> movies;
  while(file.good()){
    getline(file, str);
    strs = Str(str, ';');
    Movie movie = data(strs);
    movies.push_back(movie);
  }

  output<< "Part A" << endl;

  int totalLength = accumulate(movies, movies.size());
  output<< "The sum of total length is: ";
  output<< totalLength << "\n"<< endl;

  output<< "Part B" << endl;

  vector<Movie> m = sort(movies);
  for(auto s: m){
    output<<(s.title.c_str());
    output<<((" : " + to_string(s.popularity)).c_str());
    output<< endl;
  }
  
  output << "\n" <<  "Part C" << endl;

  string find = find_data(movies, "Kulik");
  output<< "Finding Occurance of 'Kulik': " << endl;
  output<< find << "\n"<< endl;

  output<< "Part D" << endl;
  
  string a = "Action";
  string b = "Comedy";
  vector<vector<int> > year;
  
  year = Unique(movies, a, b);
  
  output<< "Unique years for " << a << " movies: ";
  for (int s: year[0])
    output << s << ", ";
  output << endl;
  
  output << "Unique years for " << b << " movies: ";
  for (int s: year[1])
    output << s << ", ";
  output << endl;
  

  output << "Unique years of " << a << " and " << b << " are "<< (equalYear(year[0], year[1]) ? "equal. " : "not equal. ") << endl;


  return 0;
}