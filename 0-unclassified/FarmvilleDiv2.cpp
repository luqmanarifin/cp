#include <bits/stdc++.h>

using namespace std;

class FarmvilleDiv2 {
public:
  int minTime(vector<int> t, vector<int> c, int val) {
    int ans = 0, n = t.size();
    for(int i = 0; i < n; i++) {
      ans += t[i];
    }
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        if(c[i] > c[j]) {
          swap(c[i], c[j]);
          swap(t[i], t[j]);
        }
      }
    }
    for(int i = 0; i < n; i++) {
      int del = min(t[i], val / c[i]);
      val -= del * c[i];
      ans -= del;
    }
    return ans;
  }
};

/*
int main() {
  int l = 0;
  int r = 0;
  
  FarmvilleDiv2 FarmvilleDiv2;
  cout << FarmvilleDiv2.minTime() << endl;
  
  return 0;
}

*/