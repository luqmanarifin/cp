#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<string, int> g[N];
long long s[N];
char str[N];

vector<string> ans;
long long th;

void dfs(int v, string now) {
  ans.push_back("  " + now + " " + to_string(s[v]));
  if (g[v].size())
    ans.back()[0] = '+';
  if (s[v] < th) return;
  int cnt = 0;
  for (auto it : g[v]) {
    cnt += s[it.second] >= th;
  }
  if (cnt == 0) return;
  ans.back()[0] = '-';
  for (auto it : g[v]) {
    int u = it.second;
    dfs(u, now + it.first + "/");
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int node = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%s %d", str, &x);
    int now = 0;
    int len = strlen(str);
    s[now] +=x;
    for (int j = 0; j < len;) {
      ++j;
      int l = 0;
      while (j + l < len && str[j+l] != '/') ++l;
      string nx = string(str+j, str+j+l);
      j += l;
      if (j == len) break;
      int u;
      auto it = g[now].find(nx);
      if (it == g[now].end()) {
        u = node++;
        g[now][nx] = u;
      }
      else
        u = it->second;
      now = u;
      s[now] += x;
    }
  }
  scanf("%lld", &th);
  dfs(0, "/");
  if (ans.empty())
    ans.push_back("+ / " + to_string(s[0]));
  for (int i = 0; i < ans.size(); ++i) {
    printf("%s\n", ans[i].c_str());
  }
  return 0;
}
