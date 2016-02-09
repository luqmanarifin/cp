#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9;

bool bad[N];
int dp[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for(int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    if(v < N) bad[v] = 1;
  }
  for(int i = 0; i < N; i++) dp[i] = inf;
  int now = 1;
  for(int i = 1; i <= n; i++) {
    while(bad[now] || dp[now] <= k) now++;
    dp[now] = 1;
    for(int j = 2; j * now < N; j++) {
      dp[j * now] = min(dp[j * now], dp[j] + 1);
    }
    if(i > 1) printf(" ");
    printf("%d", now);
  }
  printf("\n");
  return 0;
}
