#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, mod, at[N], di[N];
int bit[N];

void update(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

vector<int> p[N];     // valuenya berapa aja, descending
vector<int> dp[N];    // munculnya berapa kali

void add(int i, int j, int val) {
  for (; j >= 0; j = (j & (j + 1)) - 1) {
    dp[i][j] += val;
    dp[i][j] %= mod;
  }
}

int find(int i, int j) {
  int ret = 0;
  for (; j < dp[i].size(); j |= j + 1) {
    ret += dp[i][j];
    ret %= mod;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &mod);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int best = -1;
  p[0].push_back(0);
  dp[0].push_back(1);
  for (int i = 0; i < n; i++) {
    int now = find(a[i] - 1) + 1;
    update(a[i], now);
    at[a[i]] = now;
    di[a[i]] = p[now].size();
    p[now].push_back(a[i]);
    dp[now].push_back(0);
    best = max(best, now);
  }
  for (int i = 0; i < N; i++) {
    sort(p[i].begin(), p[i].end());
  }
  for (int i = 0; i < n; i++) {
    int now = at[a[i]];
    int it = lower_bound(p[now - 1].begin(), p[now - 1].end(), a[i]) - p[now - 1].begin();
    int cur = find(now - 1, p[now - 1].size() - it);
    add(now, di[a[i]], cur);
  }
  cout << find(best, 0) << endl;
  return 0;
}
