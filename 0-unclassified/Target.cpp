#include <bits/stdc++.h>

using namespace std;

class Target {
public:
  vector <string> draw(int n) {
    vector<string> ret;
    ret.resize(n);
    for(int i = 0; i < n; i++) {
      if(i % 2 == 0) {
        for(int j = 0; j < i; j++) {
          if(j % 2 == 0)
            ret[i].push_back(' ');
          else
            ret[i].push_back('#');
        }
        for(int j = i; j < n - i; j++) {
          ret[i].push_back('#');
        }
        for(int j = n - i; j < n; j++) {
          if(j % 2 == 0)
            ret[i].push_back(' ');
          else
            ret[i].push_back('#');
        }
      }
    }
    return ret;
  }
};