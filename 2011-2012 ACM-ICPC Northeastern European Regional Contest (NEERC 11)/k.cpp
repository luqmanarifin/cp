#include <bits/stdc++.h>

using namespace std;

const string NAME = "kingdom";

const int N = 2e5 + 5;
vector<int> g[N];
vector<int> s[N];
vector<pair<int, int> > ans;
void dfs(int v, int par = -1) {
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    if (s[u].size() == 2) {
      if (s[v].size() > 0) {
        ans.emplace_back(s[v].back(), s[u][0]);
        s[v].pop_back();
      }
      else
        s[v].push_back(s[u][0]);
      s[v].push_back(s[u][1]);
    }
    else if (s[u].size() == 1) {
      if (s[v].size() > 1) {
        ans.emplace_back(s[v].back(), s[u][0]);
        s[v].pop_back();
      }
      else
        s[v].push_back(s[u][0]);
    }
  }
  while (s[v].size() > 2) {
    int x = s[v].back(); s[v].pop_back();
    int y = s[v].back(); s[v].pop_back();
    ans.emplace_back(x,y);
  }
  if (s[v].empty())
    s[v].push_back(v);
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root = 0;
  for (int i = 0; i < n; ++i)
    if (g[i].size() > g[root].size())
      root = i;
  dfs(root);
  if (s[root].size() == 1 && s[root][0] != root)
    ans.emplace_back(root, s[root][0]);
  else if (s[root].size() == 2)
    ans.emplace_back(s[root][0], s[root][1]);
  printf("%d\n", ans.size());
  for (auto e : ans) {
    printf("%d %d\n", e.first + 1, e.second + 1);
  }

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
