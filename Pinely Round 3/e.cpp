#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
int flip[N], pressed[N];
vector<int> s;
vector<pair<int, int>> rules[N];

bool dfs(int now, int cur, int res) {
  if (now > n) return !s.empty();
  // try to make this on
  if (res > 0) {
    int need_to_press = ((cur & (1 << now)) == 0);
    if (need_to_press) {
      pressed[now] = 1;
      s.push_back(now);
    }
    bool good = 1;
    for (auto it : rules[now]) {
      if (it.second) {
        if (pressed[now] && !pressed[it.first]) {
          good = 0;
          break;
        }
      } else {
        if (pressed[it.first] && !pressed[now]) {
          good = 0;
          break;
        }
      }
    }
    if (good) {
      int nex_cur = (cur ^ (need_to_press? flip[now] : 0));
      if (dfs(now + 1, nex_cur, res - 1)) return 1;
    }
    if (need_to_press) {
      pressed[now] = 0;
      s.pop_back();
    }
  }
  // try to make this off
  {
    int need_to_press = !!(cur & (1 << now));
    if (need_to_press) {
      pressed[now] = 1;
      s.push_back(now);
    }
    bool good = 1;
    for (auto it : rules[now]) {
      if (it.second) {
        if (pressed[now] && !pressed[it.first]) {
          good = 0;
          break;
        }
      } else {
        if (pressed[it.first] && !pressed[now]) {
          good = 0;
          break;
        }
      }
    }
    if (good) {
      int nex_cur = (cur ^ (need_to_press? flip[now] : 0));
      if (dfs(now + 1, nex_cur, res)) return 1;
    }
    if (need_to_press) {
      pressed[now] = 0;
      s.pop_back();
    }
  }
  return 0;
}

vector<int> solve() {
  s.clear();
  for (int i = 1; i <= n; i++) pressed[i] = 0;
  if (dfs(1, 0, n / 5)) return s;
  return vector<int>(0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      rules[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (u < v) {
        rules[v].emplace_back(u, 0);
      } else {
        rules[u].emplace_back(v, 1);
      }
    }
    if (n >= 20) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) printf("%d%c", i, i == n? '\n' : ' ');
      continue;
    }
    for (int i = 1; i <= n; i++) {
      flip[i] = 0;
      for (int j = i; j <= n; j += i) {
        flip[i] |= (1 << j);
      }
    }
    auto ans = solve();
    if (ans.empty()) {
      printf("-1\n");
    } else {
      printf("%d\n", ans.size());
      for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], i + 1 == ans.size()? '\n' : ' ');
    }
  }

  return 0;
}
