#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;

bool is[N], v[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(is, 0, sizeof(is)); 
    memset(v, 0, sizeof(v)); 

    int n;
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') is[i] = 1;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int x;
      scanf("%d", &x);
      v[x] ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i]) {
        for (int j = i; j <= n; j += i) {
          is[j] ^= 1;
        }
      }
      if (is[i]) {
        ans++;
        for (int j = i; j <= n; j += i) {
          is[j] ^= 1;
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
