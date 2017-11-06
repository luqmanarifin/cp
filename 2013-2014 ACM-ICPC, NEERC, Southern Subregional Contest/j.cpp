#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct item {
  item() {}
  item(int prob, int time, int yet, int id, int solve) :
    prob(prob), time(time), yet(yet), id(id), solve(solve) {}
    
  // state
  int prob;
  int time;
  int yet;
  
  int id;  // 0 kalo ga ngapa ngapain
  int solve;
};

const int N = 31;
const int T = 1e4 + 5;

int dp[N][T][N];
int s[N], t[N], ori[N];
int pre[T];

item b[N][T][N];

int get(int l, int r) {
  return pre[r] - pre[l - 1];
}

vector<int> get(int l, int r, int v) {
  vector<int> ret;
  for (int i = r; i >= l; i--) {
    if (get(i, i)) ret.push_back(i);
    if (ret.size() == v) return ret;
  }
  assert(0);
}

int main() {
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < T; i++) {
      for (int j = 0; j < N; j++) {
        dp[k][i][j] = -inf;
      }
    }
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int>> p;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", s + i, t + i);
    p.emplace_back(t[i], s[i], i);
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    tie(t[i + 1], s[i + 1], ori[i + 1]) = p[i];
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l++; r++;
    for (int j = l; j < r; j++) pre[j]++;
  }
  for (int i = 1; i < T; i++) pre[i] += pre[i - 1];
  
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < T; j++) {
      for (int k = 0; k <= n; k++) {
        int cur = dp[i][j][k] + s[i + 1];
        for (int l = 0; l <= k; l++) {
          int ntime = j + t[i + 1] + l;
          if (get(j + 1, ntime) < l) break;
          if (ntime >= T) break;
          int nyet = k + 1 - l;
          if (cur > dp[i + 1][ntime][nyet]) {
            dp[i + 1][ntime][nyet] = cur;
            b[i + 1][ntime][nyet] = item(i, j, k, i + 1, l);
          }
        }
      }
    }
    for (int j = 0; j < T; j++) {
      for (int k = 0; k <= n; k++) {
        if (dp[i][j][k] > dp[i + 1][j][k]) {
          dp[i + 1][j][k] = dp[i][j][k];
          b[i + 1][j][k] = item(i, j, k, 0, 0);
        }
        if (j + 1 < T && dp[i + 1][j][k] > dp[i + 1][j + 1][k]) {
          dp[i + 1][j + 1][k] = dp[i + 1][j][k];
          b[i + 1][j + 1][k] = item(i + 1, j, k, 0, 0);
        }
        if (j + 1 < T && k && get(j + 1, j + 1) && dp[i + 1][j][k] > dp[i + 1][j + 1][k - 1]) {
          dp[i + 1][j + 1][k - 1] = dp[i + 1][j][k];
          b[i + 1][j + 1][k - 1] = item(i + 1, j, k, 0, 1);
        }
      }
    }
  }
  //puts("dp done");
  
  int ans = dp[n][T - 1][0];
  vector<int> pro, sub;
  int i = n, j = T - 1, k = 0;
  while (i > 0) {
    //printf("%d %d %d\n", i, j, k);
    if (b[i][j][k].id) {
      pro.push_back(b[i][j][k].id);
    }
    if (b[i][j][k].solve) {
      auto ret = get(b[i][j][k].time + 1, j, b[i][j][k].solve);
      for (auto it : ret) sub.push_back(it);
    }
    int ni = b[i][j][k].prob;
    int nj = b[i][j][k].time;
    int nk = b[i][j][k].yet;
    i = ni;
    j = nj;
    k = nk;
  }
  reverse(pro.begin(), pro.end());
  sort(sub.begin(), sub.end());
  assert(pro.size() == sub.size());
  printf("%d %d\n", ans, pro.size());
  for (int i = 0; i < pro.size(); i++) {
    printf("%d %d\n", ori[pro[i]], sub[i] - 1);
  }
  
  return 0;
}