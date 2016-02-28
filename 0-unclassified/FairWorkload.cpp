#include <bits/stdc++.h>

using namespace std;

class FairWorkload {
public:
  int getMostWork(vector <int> folders, int n) {
    int ret = 1e9;
    for(int mask = 0; mask < (1 << (folders.size() - 1)); mask++) {
      if(__builtin_popcount(mask) != n - 1) {
        continue;
      }
      int temp = 0;
      int cur = 0;
      for(int i = 0; i < folders.size(); i++) {
        temp += folders[i];
        if(mask & (1 << i)) {
          cur = max(cur, temp);
          temp = 0;
        }
      }
      cur = max(cur, temp);
      ret = min(ret, cur);
    }
    return ret;
  } 
};