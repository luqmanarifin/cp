#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const short inf = 32000;

int size[N], h[N], ada;
string s[N];
short dp[N][325];
bool take[N][325];

int dfs(int n, int now) {
  if (n == 0) return 0;
  if (n < 0 || now == ada) return inf;
  if (dp[n][now] != -1) return dp[n][now];
  if (dfs(n - size[now], now + 1) + 1 > dfs(n, now + 1)) {
    dp[n][now] = dfs(n, now + 1);
  } else {
    dp[n][now] = dfs(n - size[now], now + 1) + 1;
    take[n][now] = 1;
  }
  //printf("dfs %d %d: %d\n", n, now, dp[n][now]);
  return dp[n][now];
}

void backtrack(int n, int now) {
  if (n == 0) return;
  if (take[n][now]) {
    printf(" %s", s[now].c_str());
    backtrack(n - size[now], now + 1);
  } else {
    backtrack(n, now + 1);
  }
}

int main() {
  vector<tuple<int, int, string>> all;
  long long now = 1;
  for (int i = 2; now + 1LL * i * i < N; i++) {
    now += 1LL * i * i;
    all.emplace_back(-now, -i, to_string(i) + "H");
  }
  
  now = 1;
  for (int i = 3; now + 1LL * i * i < N; i += 2) {
    now += 1LL * i * i;
    all.emplace_back(-now, -i, to_string(i) + "L");
  }
  
  now = 4;
  for (int i = 4; now + 1LL * i * i < N; i += 2) {
    now += 1LL * i * i;
    all.emplace_back(-now, -i, to_string(i) + "L");
  }
  sort(all.begin(), all.end());
  for (int i = 0; i < all.size(); i++) {
    tie(size[i], h[i], s[i]) = all[i];
    size[i] = -size[i];
    h[i] = -h[i];
    //printf("%d %d %s\n", size[i], h[i], s[i].c_str());
  }
  ada = all.size();
  //cout << ada << endl;
  
  memset(dp, -1, sizeof(dp));
  int n;
  scanf("%d", &n);
  int tc = 0;
  while (n) {
    tc++;
    printf("Case %d:", tc);
    
    int ans = dfs(n, 0);
    if (ans >= inf) {
      puts(" impossible");
    } else {
      backtrack(n, 0);
      printf("\n");
    }
    
    scanf("%d", &n);
  }
  
  return 0;
}
