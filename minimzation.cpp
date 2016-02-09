#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long inf = 1e18;

vector<int> p[N];
vector<long long> dp[N];
int a[N];

int id(int at, int k) {
  int ret = lower_bound(p[at].begin(), p[at].end(), k) - p[at].begin();
  if(!(0 <= ret && ret < p[at].size()) || p[at][ret] != k) return -1;
  return ret;
}

int get(int l, int r) {
  return a[r] - a[l];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + n);
  
  int h = n / k;
  p[0].push_back(0);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= 1; j++) {
      if(i - h - j >= 0) {
        for(auto it : p[i - h - j]) {
          p[i].push_back(it + 1);
        }
      }
    }
    sort(p[i].begin(), p[i].end());
    p[i].resize(distance(p[i].begin(), unique(p[i].begin(), p[i].end())));
  }
  /*
  for(int i = 1; i <= n; i++) {
    for(auto it : p[i]) {
      printf("%d ", it);
    }
    printf("\n");
  }
  */
  dp[0].assign(1, 0);
  for(int i = 1; i <= n; i++) {
    dp[i].assign(p[i].size(), inf);
    for(int j = 0; j < p[i].size(); j++) {
      for(int d = 0; d <= 1; d++) {
        if(i - h - d < 0) continue;
        int at = id(i - h - d, p[i][j] - 1);
        if(at == -1) continue;
        dp[i][j] = min(dp[i][j], dp[i - h - d][at] + get(i - h - d + 1, i));
      }
    }
  }
  /*
  puts("JANCOK");
  for(int i = 1; i <= n; i++) {
    for(auto it : dp[i]) {
      printf("%I64d ", it);
    }
    printf("\n");
  }
  */
  printf("%I64d\n", dp[n][id(n, k)]);
  return 0;
}
