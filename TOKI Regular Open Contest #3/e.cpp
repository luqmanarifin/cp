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

const int inf = 2e9;

vector<vector<int> > inverse(vector<vector<int> > a, int n, int m) {
  vector<vector<int> > ret;
  ret.resize(m);
  for (int i = 0; i < m; i++) {
    ret[i].resize(n);
    for (int j = 0; j < n; j++) {
      ret[i][j] = a[j][i];
    }
  }
  return ret;
}

int n, m, k;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  
  scanf("%d %d %d", &n, &m, &k);
  vector<vector<int> > a;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  if (n > m) {
    a = inverse(a, n, m);
    swap(n, m);
  }
  vector<vector<vector<int> > > dp;
  dp.resize(n);
  for (int i = 0; i < n; i++) {
    dp[i].resize(n);
    for (int j = 0; j < n; j++) {
      dp[i][j].assign(2, -inf);
    }
  }
  dp[0][0][0] = 0;
  for (int s = 1; s <= n + m - 2; s++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!valid(i, s - i) || !valid(j, s - j)) continue;
        int add = (i != j? a[i][s-i] + a[j][s-j] : a[i][s-i] + (a[i][s-i] ^ k));
        for (int dx = 0; dx <= 1; dx++) {
          if (i - dx < 0) continue;
          for (int dy = 0; dy <= 1; dy++) {
            if (j - dy < 0) continue;
            upd(dp[i][j][s % 2], dp[i-dx][j-dy][1 - (s % 2)] + add);
          }
        }
      }
    }
  }
  cout << dp[n-1][n-1][(n + m - 2) % 2] << endl;
  return 0;
}
