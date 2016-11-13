#include <bits/stdc++.h>

using namespace std;

const int N = 805;

int d[N];
int a[N];
int b[N];
int dp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = i;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u]++;
    a[v]--;
  }
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  for (int i = 1; i <= n; i++) assert(b[i]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int maxi = 0;
    for (int j = 0; j < i; j++) {
      if (b[j] > b[i]) {
        maxi = max(maxi, dp[j]); 
      }
    }
    dp[i] = maxi + 1;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}