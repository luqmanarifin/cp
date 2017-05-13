#include "assistant.h"

#include <bits/stdc++.h>

using namespace std;

int ddone[1 << 12], tto[1 << 12];
int NN, KK;

void initAssistant(int n, int k) {
  NN = n;
  KK = k;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) != k) continue;
    bool found = 0;
    for (int i = 0; i < n; i++) if ((mask & (1 << i)) == 0) {
      int cur = (mask | (1 << i));
      if (!ddone[cur]) {
        tto[mask] = cur;
        ddone[cur] = mask;
        found = 1;
        break;
      }
    }
    assert(found);
  }
}

int giveClue(std::vector<int> cards) {
  int mask = 0;
  for (auto it : cards) {
    mask |= (1 << (it - 1));
  }
  int ret = (tto[mask] ^ mask);
  for (int i = 0; i < NN; i++) if (ret & (1 << i)) {
    return i + 1;
  }
}
