#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

vector<int> to[17][1 << 16];
int sum[17][1 << 16];
int a[20][20], dp[17][1 << 16];
bool bad[1 << 16];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  for (int i = 0; i < (1 << 16); i++) {
    for (int j = 1; j < 16; j++) {
      if ((i & (1 << j)) && (i & (1 << (j-1)))) {
        bad[i] = 1;
      }
    }
  }

  for (int n = 1; n <= 16; n++) {
    for (int i = 0; i < (1 << n); i++) {
      if (bad[i]) continue;
      for (int j = (1 << n) - 1; j >= 0; j = ((j - 1) & (~i))) {
        if (bad[j]) continue;
        bool bad = 0;
        for (int x = 0; x < n; x++) {
          if (j & (1 << x)) {
            if (x - 1 >= 0 && (i & (1 << (x - 1)))) {
              bad = 1;
              break;
            }
            if (x + 1 < n && (i & (1 << (x + 1)))) {
              bad = 1;
              break;
            }
          }
        }
        if (!bad) {
          to[n][i].push_back(j);
        }
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int mask = 1; mask < (1 << n); mask++) {
        int at = __builtin_clz(mask) ^ 31;
        sum[i][mask] = sum[i][mask - (1 << at)] + a[i][at];
      }
    }
    for (int i = 0; i < (1 << n); i++) dp[0][i] = sum[0][i];
    for (int i = 1; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        dp[i][mask] = 0;
        for (auto it : to[n][mask]) {
          upd(dp[i][mask], dp[i-1][it] + sum[i][mask]);
        }
      }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      upd(ans, dp[n-1][mask]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
