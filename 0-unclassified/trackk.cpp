#include <bits/stdc++.h>

using namespace std;

const int prime[] = {71, 89};
const long long mod[] = {(long long)2e9 + 143, (long long)2e9 + 89};
const int inf = 2e9;
const int much = 1e7;
const int N = 3005;

pair<long long, int> all[much];
long long ada[much];
int as, key[much];

char a[N], b[N];
long long pb[N][2], power[N][2];

int dp[N], bef[N], track[N];

int find(long long ha) {
  int p = lower_bound(ada, ada + as, ha) - ada;
  if(p < 0 || p >= as) return -1;
  if(ada[p] != ha) return -1;
  return key[p];
}

void backtrack(int m) {
  if(m == 0) return;
  backtrack(bef[m]);
  printf("%d %d\n", track[m] / N, track[m] % N);
}

int main() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      power[i][j] = power[i - 1][j] * prime[j] % mod[j];
    }
  }
  scanf("%s %s", a + 1, b + 1);
  int n = strlen(a + 1);
  int m = strlen(b + 1);
  for(int i = 1; i <= m; i++) {
    for(int j = 0; j < 2; j++) {
      pb[i][j] = (pb[i - 1][j] * prime[j] + b[i] - 'a' + 1) % mod[j];
    }
  }
  for(int i = 1; i <= n; i++) {
    long long ha[2] = {};
    for(int k = i; k <= n; k++) {
      for(int j = 0; j < 2; j++) {
        ha[j] = (ha[j] * prime[j] + a[k] - 'a' + 1) % mod[j];
      }
      all[as++] = make_pair(ha[0] * mod[1] + ha[1], i * N + k);
    }
    ha[0] = ha[1] = 0;
    for(int k = i; k >= 1; k--) {
      for(int j = 0; j < 2; j++) {
        ha[j] = (ha[j] * prime[j] + a[k] - 'a' + 1) % mod[j];
      }
      all[as++] = make_pair(ha[0] * mod[1] + ha[1], i * N + k);
    }
  }
  sort(all, all + as);
  int asu = 0;
  for(int i = 0; i < as; i++) {
    if(i == 0 || all[i].first != all[i - 1].first) {
      ada[asu] = all[i].first;
      key[asu++] = all[i].second;
    }
  }
  as = asu;
  
  for(int i = 1; i < N; i++) {
    dp[i] = inf;
  }
  for(int i = 1; i <= m; i++) {
    long long tmp[2];
    for(int k = i - 1; k >= 0; k--) {
      for(int j = 0; j < 2; j++) {
        tmp[j] = pb[i][j] - pb[k][j] * power[i - k][j] % mod[j];
        if(tmp[j] < 0) tmp[j] += mod[j];
      }
      int ret = find(tmp[0] * mod[1] + tmp[1]);
      if(ret != -1 && dp[k] + 1 < dp[i]) {
        dp[i] = dp[k] + 1;
        bef[i] = k;
        track[i] = ret;
      }
    }
  }
  if(dp[m] == inf) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dp[m]);
  backtrack(m);
  return 0;
}
