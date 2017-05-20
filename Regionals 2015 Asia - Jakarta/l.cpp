#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}

vector<int> a[N];
long long g[N];


int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(g, 0, sizeof(g));
    for (int i = 0; i < N; i++) a[i].clear();
    
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int m;
      scanf("%d", &m);
      while (m--) {
        int v;
        scanf("%d", &v);
        a[i].push_back(v);
      }
      for (int j = 1; j < a[i].size(); j++) {
        g[i] = gcd(g[i], abs(a[i][j] - a[i][j-1]));
      }
      sum += a[i][0];
    }
    long long ans = sum;
    for (int i = 0; i < n; i++) ans = gcd(ans, g[i]);
    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}
