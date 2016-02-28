#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N];
int cnt[N];
int a[N];
bool is[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    dp[a[i]]++;
    cnt[a[i]]++;
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    for(int j = 2 * a[i]; j < N; j += a[i]) {
      dp[j] = max(dp[j], dp[a[i]] + cnt[j]);
    }
  }
  int ans = 1;
  for(int i = 0; i < n; i++) {
    ans = max(ans, dp[a[i]]);
  }
  cout << ans << endl;
  return 0;
}
