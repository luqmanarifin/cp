#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N], d[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    m += k;
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", b + i);
      c[i] = a[i] - b[i];
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", d + i);
    }
    sort(c, c + n);
    sort(d, d + m);
    reverse(c, c + n);
    reverse(d, d + m);
    long long ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
      while(j < m && d[j] > c[i]) j++;
      if(j < m) {
        c[i] -= d[j];
        j++;
      }
      ans += c[i];
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
