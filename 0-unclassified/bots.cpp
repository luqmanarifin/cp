#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 12;

bool done[N];

int main() {
  for(int n = 0; n < 5; n++) {
    int t = n * 2;
    vector<pair<int, int>> p;
    p.emplace_back(0, 0);
    for(int mask = 0; mask < (1 << t); mask++) {
      if(__builtin_popcount(mask) != n) continue;
      for(int i = 1; i <= t; i++) {
        p.emplace_back(i, mask & ((1 << i) - 1));
      }
    }
    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));
    /*
    for(auto it : p) {
      printf("%d %d\n", it.first, it.second);
    }
    */
    printf("CAK %d\n", p.size());
  }
  
  return 0;
}
