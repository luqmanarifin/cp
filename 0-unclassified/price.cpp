#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

long long get(int l, int r) {
  return a[r] - a[l - 1];
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++) {
      scanf("%I64d", a + i);
      a[i] += a[i - 1];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      int l = i - 1, r = n;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(get(i, mid) <= p) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      ans += l - i + 1;
    }
    printf("Case #%d: %I64d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }
  return 0;
}
