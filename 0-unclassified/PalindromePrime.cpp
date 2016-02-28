#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

class PalindromePrime {
public:
  vector<bool> is;
  
  bool isPalin(int a) {
    vector<int> v;
    while(a > 0) {
      v.push_back(a % 10);
      a /= 10;
    }
    int n = v.size();
    for(int i = 0; i < n; i++) {
      if(v[i] != v[n - 1 - i]) return 0;
    }
    return 1;
  }
  int count(int l, int r) {
    is.resize(N);
    is[1] = 1;
    for(int i = 2; i < N; i++) {
      if(!is[i]) {
        for(int j = i * i; j < N; j += i) {
          is[j] = 1;
        }
      }
    }
    int ans = 0;
    for(int i = l; i <= r; i++) {
      if(!is[i] && isPalin(i)) {
        ans++;
      }
    }
    return ans;
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  
  PalindromePrime palindromePrime;
  cout << palindromePrime.count(1, 1000) << endl;
  
  return 0;
}
*/