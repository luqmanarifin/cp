#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int ans[N];

inline long long pre(int n) {
  return 1LL * n * (n + 1) / 2;
}

// return 1 if found
bool dfs(int now, long long sum) {
  if (sum == 0) return 1;
  if (now == 0) return 0;
  if (ans[now] == 2) return dfs(now - 1, sum);
  if (now <= sum) {
    ans[now] = 1;
    if (dfs(now - 1, sum - now)) return 1;
    ans[now] = 0;
  }
  return dfs(now - 1, sum);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ans, 0, sizeof(ans));
    
    int k, n;
    scanf("%d %d", &k, &n);
    ans[k] = 2;
    long long all = pre(n) - k;
    if (all % 2) {
      puts("impossible");
    } else {
      if (dfs(n, all / 2)) {
        for (int i = 1; i <= n; i++) printf("%d", ans[i]); printf("\n");
      } else {
        puts("impossible");
      }
    }
  }

  return 0;
}
