#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const long long inf = 1e18;

int a[N][5];
multiset<long long> s[1 << 5];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
    for (int mask = 0; mask < (1 << m); mask++) {
      long long val = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) {
          val += a[i][j]; 
        } else {
          val -= a[i][j];
        }
      }
      s[mask].insert(val);
    }
  }
  long long ans = -inf;
  for (int j = 0; j < (1 << m); j++) {
    ans = max(ans, *(s[j].rbegin()) - *(s[j].begin()));
  }
  printf("%lld\n", ans);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int i;
    scanf("%d", &i);
    i--;
    
    for (int mask = 0; mask < (1 << m); mask++) {
      long long val = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) {
          val += a[i][j]; 
        } else {
          val -= a[i][j];
        }
      }
      s[mask].erase(s[mask].find(val));
    }
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    for (int mask = 0; mask < (1 << m); mask++) {
      long long val = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) {
          val += a[i][j]; 
        } else {
          val -= a[i][j];
        }
      }
      s[mask].insert(val);
    }
    
    long long ans = -inf;
    for (int j = 0; j < (1 << m); j++) {
      ans = max(ans, *(s[j].rbegin()) - *(s[j].begin()));
    }
    printf("%lld\n", ans);
  }

  return 0;
}
