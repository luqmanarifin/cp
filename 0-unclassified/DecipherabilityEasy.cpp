#include <bits/stdc++.h>

using namespace std;

class DecipherabilityEasy {
public:
  string check(string a, string b) {
    int lena = a.length();
    for(int i = 0; i < lena; i++) {
      string temp = "";
      for(int j = 0; j < lena; j++) {
        if(i != j) temp.push_back(a[j]);
      }
      if(temp == b) {
        return "Possible";
      }
    }
    return "Impossible";
  }
};