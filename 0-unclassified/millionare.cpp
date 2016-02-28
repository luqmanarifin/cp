#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char a[N], b[N];
int v[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d %s %s", &n, a, b);
    int s = 0;
    for(int i = 0; i < n; i++) {
      s += a[i] == b[i];
    }
    for(int i = 0; i <= n; i++) {
      scanf("%d", &v[i]);
    }
    int ans = -1;
    for(int i = 0; i <= s; i++) {
      ans = max(ans, v[i]);
    }
    if(s == n) ans = v[n];
    printf("%d\n", ans);
  }
  
  return 0;
}
