// optimizer in source code (or change O3 to O2)
#pragma GCC optimize("O2")

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

const long long mod = 1e9 + 7;
const int N = 105;

#define matrix vector<vector<long long> >

matrix create(int n, int m) {
  matrix c(n, vector<long long>(m, 0));
  return c;
}

matrix one(int n) {
  matrix c = create(n, n);
  for (int i = 0; i < n; i++) c[i][i] = 1;
  return c;
}

matrix mul(matrix a, matrix b) {
  int n = a.size();
  int m = b[0].size();
  matrix c = create(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < a[0].size(); k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mod;
      }
    }
  }
  return c;
}


matrix cache[30];

int cnt[N];
int a[N * N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  matrix trans = create(101, 101);
  for (int i = 1; i <= 100; i++) {
    for (int j = i; j <= 100; j++) {
      trans[i][j] = cnt[j];
    }
  }
  cache[0] = trans;
  for (int i = 1; i < 30; i++) {
    cache[i] = mul(cache[i-1], cache[i-1]);
  } 

  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (z == 0) {
      int ans;
      if (x == y) {
        ans = 1;
      } else {
        ans = 0;
      }
      printf("%d\n", ans);
      continue;
    }
    z--;
    matrix now = create(1, 101);
    now[0][a[x]]++;

    for (int i = 0; i < 25; i++) {
      if (z & (1 << i)) {
        now = mul(now, cache[i]);
      }
    }
    long long ans = 0;
    for (int i = 0; i <= a[y]; i++) {
      ans += now[0][i];
    }
    printf("%lld\n", ans % mod);
  }

  return 0;
}
