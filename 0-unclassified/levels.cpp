#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 5;
const int inf = 1e9;

long long a[N];
int to[N];

long long get(int l, int r) {
  if(l > r) return 0;
  return a[r] - (l? a[l - 1] : 0);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  for(int i = 0; i < 2 * n; i++) {
    a[i + n] = a[i];
  }
  int newn = 2 * n;
  for(int i = 1; i < newn; i++) {
    a[i] += a[i - 1];
  }
  
  while(q--) {
    long long lim;
    scanf("%I64d", &lim);
    int r = 0;
    for(int i = 0; i < newn; i++) {
      while(r < newn && r < i + n && get(i, r) <= lim) {
        r++;
      }
      to[i] = r - 1;
    }
    int at = -1, mini = inf;
    for(int i = 0; i < n; i++) {
      if(get(i + n - 1, to[i] + n) <= lim && to[i] - i + 1 != n) {
        continue;
      }
      if(to[i] - i + 1 < mini) {
        mini = to[i] - i + 1;
        at = i;
      }
    }
    int ans = inf;
    for(int it = at; it <= to[at]; it++) {
      int st = it;
      if(st >= n) st -= n;
      int cur = 0;
      for(int i = st; i < st + n; i++) {
        cur++;
        i = to[i];
      }
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
