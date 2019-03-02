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

const int N = 2e5 + 5;

long long a[N], pre[N], suf[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      pre[i] = pre[i-1] + a[i];
    } else {
      pre[i] = pre[i-1] - a[i];
    }
  }
  for (int i = n; i >= 1; i--) {
    if (i % 2) {
      suf[i] = suf[i+1] + a[i];
    } else {
      suf[i] = suf[i+1] - a[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    long long now = 0;
    if (i % 2) {
      now = pre[i-1] - suf[i+1];
    } else {
      now = pre[i-1] - suf[i+1];
    }
    // printf("%d: %lld %lld %lld\n", i, now, pre[i-1], suf[i+1]);
    if (now == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
