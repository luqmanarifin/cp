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

const int N = 1e5 + 5;

int bit[N];

int find(int i) {
  int ret = 0;
  for (; i < N; i |= i + 1) {
    ret += bit[i];
  }
  return ret;
}

void add(int i) {
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    bit[i]++;
  }
}

int a[N], b[N], p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(bit, 0, sizeof(bit));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", b + i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int v = p[b[i]];
      ans += find(v + 1);
      add(v);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
