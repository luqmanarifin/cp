#include <bits/stdc++.h>

using namespace std;

const int N = 251;

#define int long long

int ans[N][N][N];

int dfs(int rem, int p, int at) {
  if(ans[rem][p][at] != -1) return ans[rem][p][at];
  if(rem == 0) return ans[rem][p][at] = 1;
  if(rem < p) return ans[rem][p][at] = 0;
  ans[rem][p][at] = 1;
  for(int i = max(1LL, p); i + i <= rem; i++) {
    ans[rem][p][at] += dfs(rem - 2 * i, i, at);
  }
  return ans[rem][p][at];
}

main() {
  memset(ans, -1, sizeof(ans));
  for(int i = 1; i < N; i++) {
    printf("%I64d,", dfs(i, 0, i));
    cerr << i << " done!" << endl;
  }
  int n;
  scanf("%d", &n);
  while(n) {
    printf("%d\n", ans[n]);
    scanf("%d", &n);
  }
  return 0;
}