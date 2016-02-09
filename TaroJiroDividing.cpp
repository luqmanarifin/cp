#include <bits/stdc++.h>

using namespace std;

class TaroJiroDividing {
public:
  int getNumber(int a, int b) {
    vector<int> aa;
    while(a % 2 == 0) {
      aa.push_back(a);
      a /= 2;
    }
    aa.push_back(a);
    
    vector<int> bb;
    while(b % 2 == 0) {
      bb.push_back(b);
      b /= 2;
    }
    bb.push_back(b);
    int ret = 0;
    for(auto a : aa) {
      for(auto b : bb) {
        if(a == b) ret++;
      }
    }
    return ret;
  }
};
/*
int main() {
  TaroJiroDividing a;
  cout << a.getNumber(24, 96) << endl;
  return 0;
} */