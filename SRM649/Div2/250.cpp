#include <string> 
using namespace std; 

class DecipherabilityEasy 
{ 
public : 
  string check(string s, string t) { 
    for (int i=0; i<s.size(); i++) { 
      if (s.substr(0, i) + s.substr(i+1, s.size()) == t) return "Possible"; 
    } 
    return "Impossible"; 
  } 
};