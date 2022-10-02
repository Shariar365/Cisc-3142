/*Pseudocose:
#include <vector>
#include <iostream>
using namespace std;

int main(){

    vector<string> vector;
    string s;
    while(cin >> s)
        push s to vector;
    
    for string s in stringVector {
        for every character char c in : s{
            using toupper to capitilize every c; 
        }
    }
    for int i = 0; i != stringVector.size(); i++ {
        if i % 8 == 0 {
            cout << endl;
        }
        cout << stringVector[i] << " ";
    }

    return 0;
} */

#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    string s;
    char c;
    int i=0;
    cout  << "Write a 10 word sentence"<<endl;
    while(cin>>s)    
    {
        v.push_back(s);
        i++;
        if(i>9) break;
    }
    for(string &s : v){
        for(char &c : s){
            c = toupper(c);
        }
    }
    for (int i = 0; i != v.size(); i++){
        if (i != 0 && i % 8 == 0){
            cout << endl;
        }
        cout << v[i] << " ";
    }
    return 0;
}