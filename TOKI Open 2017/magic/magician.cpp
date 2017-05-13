#include "magician.h"

#include <bits/stdc++.h>

using namespace std;

int done[1 << 12], to[1 << 12];
int N, K;

void initMagician(int n, int k) {
  N = n;
  K = k;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) != k) continue;
    bool found = 0;
    for (int i = 0; i < n; i++) if ((mask & (1 << i)) == 0) {
      int cur = (mask | (1 << i));
      if (!done[cur]) {
        to[mask] = cur;
        done[cur] = mask;
        found = 1;
        break;
      }
    }
    assert(found);
  }
}

std::vector<int> findOriginalCards(std::vector<int> cards) {
  int mask = 0;
  for (auto it : cards) {
    mask |= (1 << (it - 1));
  }
  mask = done[mask];
  vector<int> ret;
  for (int i = 0; i < N; i++) {
    if (mask & (1 << i)) {
      ret.push_back(i + 1);
    }
  }
  return ret;
}
