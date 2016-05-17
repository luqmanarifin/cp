#include <bits/stdc++.h>

using namespace std;

map<int, int> h;

set<int> s;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(i) {
      int up = -1, lo = -1;
      auto it = s.upper_bound(num);
      if(it != s.end()) {
        up = *it;
      }
      if(it != s.begin()) {
        it--;
        lo = *it;
      }
      if(up != -1 && lo != -1) {
        if(h[up] > h[lo]) {
          printf("%d ", up);
        } else if(h[up] < h[lo]) {
          printf("%d ", lo);
        } else {
          assert(0);
        }
        h[num] = max(h[up], h[lo]) + 1;
      } else if(up != -1) {
        h[num] = h[up] + 1;
        printf("%d ", up);
      } else if(lo != -1) {
        h[num] = h[lo] + 1;
        printf("%d ", lo);
      } else {
        assert(0);
      }
    } else {
      h[num] = 1;
    }
    s.insert(num);
  }
  
  return 0;
}