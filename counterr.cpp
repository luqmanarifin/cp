#include <bits/stdc++.h>

using namespace std; 

const int N = 1e5 + 5;
const long long inf = 1e18;

long long dp[N];
int b[N], c[105], a[105];
vector<int> ans;

void backtrack(int at) {
  if(at == 0) return;
  ans.push_back(b[at]);
  backtrack(at - a[b[at]]);
}

int main() {
  int n, cost;
  scanf("%d %d", &n, &cost);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", c + i, a + i);
  }
  for(int i = 0; i < N; i++) {
    dp[i] = inf;
    b[i] = -1;
  }
  dp[0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = N - 1; j >= a[i]; j--) {
      if(dp[j - a[i]] + c[i] < dp[j]) {
        dp[j] = dp[j - a[i]] + c[i];
        b[j] = i;
      }
    }
  }
  int lega = 0;
  for(int i = 0; i < N; i++) {
    if(dp[i] <= cost) {
      lega = i;
    }
  }
  backtrack(lega);
  sort(ans.begin(), ans.end());
  printf("%d\n", lega);
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}