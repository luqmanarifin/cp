#include <bits/stdc++.h>

using namespace std;

const string NAME = "factorial";

const int N = 2e4 + 4;
vector<pair<int, int> > vp[N];
int cnt[N], val[N];
int cur[N];

pair<int, int> get() {
  int ret = 1;
  while (1) {
    int now = ret + 1;
    bool cek = 1;
    for (auto p : vp[now]) {
      if (cur[p.first] + p.second > val[p.first]) cek = 0;
    }
    if (!cek) break;
    for (auto p : vp[now])
      cur[p.first] += p.second;
    ++ret;
  }
  int mul = 1e9;
  for (int i = 2; i <= ret; ++i) {
    if (cur[i] == 0) continue;
    int c = val[i]/cur[i];
    mul = min(mul, c);
  }
  for (int i = 2; i <= ret; ++i) {
    val[i] -= cur[i] * mul;
    cur[i] = 0;
  }
  return {ret,mul};
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  for (int i = 2; i < N; ++i) if (vp[i].empty()) {
    for (int j = i; j < N; j += i) {
      int k = 0;
      int now = j;
      while ((now % i) == 0) {
        now /= i;
        ++k;
      }
      vp[j].emplace_back(i, k);
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 2; j <= x; ++j) {
      ++cnt[j];
    }
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 2; j <= x; ++j) {
      --cnt[j];
    }
  }
  for (int i = 2; i < N; ++i) {
    if (cnt[i] == 0) continue;
    for (auto p : vp[i]) {
      val[p.first] += p.second * cnt[i];
    }
  }
  bool cek = 1;
  for (int i = 2; i < N; ++i) {
    cek &= val[i] >= 0;
    if (val[i] < 0) {
      cerr << i << endl;
    }
  }
  if (!cek) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int> > ans;
  while (1) {
    pair<int, int> v = get();
    if (v.first <= 1) break;
    ans.emplace_back(v);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
