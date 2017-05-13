#include <bits/stdc++.h>

using namespace std;

bool done[1 << 12];

int main() {
  for (int n = 3; n <= 12; n++) {
    for (int k = 1; 2 * k < n; k++) {
      memset(done, 0, sizeof(done));
      for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;
        bool found = 0;
        for (int i = 0; i < n; i++) if ((mask & (1 << i)) == 0) {
          int cur = mask | (1 << i);
          if (!done[cur]) {
            done[cur] = 1;
            found = 1;
            break;
          }
        }
        assert(found);
      }
    }    
  }

  return 0;
}