#include <bits/stdc++.h>

using namespace std;

class CoinConstruction {
public:
  vector<int> construct(int k) {
    vector<int> ret;
    for (int i = 0; i < 25; i++) {
      int cur = (1 << i);
      int del = min(k, cur);
      if (del > 0) ret.push_back(del);
      k -= del;
    }
    return ret;
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  
  CoinConstruction CoinConstruction;
  vector<int> ret = CoinConstruction.construct(6);
  for (auto it : ret) printf("%d ", it);
  
  return 0;
}
*/