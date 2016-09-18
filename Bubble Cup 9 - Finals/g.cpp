#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 1e9;

char s[N][N];
int gain[N];
char a[N];

int dp[N];
int bef[N];

int en[N * N];
int beg[N * N];
int val[N * N];
set<int> id[N];

int main() {
  int n, m;
  scanf("%d %s %d", &n, a + 1, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s %d", s[i] + 1, gain + i);
  }
  int times;
  scanf("%d", &times);
  
  int now = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int len = strlen(s[j] + 1);
      bool good = 1;
      for (int k = 1; k <= len; k++) {
        if (a[i + k - 1] != s[j][k]) {
          good = 0;
          break;
        }
      }
      if (good) {
        en[now] = i + len;
        beg[now] = i;
        val[now] = gain[j];
        id[i].insert(now);
        //printf("%d: %d %d %d\n", now, beg[now], en[now], val[now]);
        now++;
      }
    }
  }
  //puts("pre done");
  int ans = 0;
  for (int tt = 0; tt < times; tt++) {
    fill(dp, dp + N, -inf);
    memset(bef, -1, sizeof(bef));
    
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
      for (auto it : id[i]) {
        if (dp[i] + val[it] > dp[en[it]]) {
          dp[en[it]] = dp[i] + val[it];
          bef[en[it]] = it;
        }
      }
      if (dp[i] > dp[i + 1]) {
        dp[i + 1] = dp[i];
        bef[i + 1] = -1;
      }
    }
    now = n + 1;
    while (now > 1) {
      //printf("%d ", now);
      if (bef[now] == -1) {
        now--;
      } else {
        int it = bef[now];
        //printf("%d: %d %d %d\n", it, beg[it], en[it], val[it]);
        ans += val[it];
        id[beg[it]].erase(it);
        now = beg[it];
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
