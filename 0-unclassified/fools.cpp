#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<int> s[N];
// ke - id
vector<pair<int, int>> edge[N];
vector<int> f[N];
int ans[N];
int iter;

int dfs(int now, int prev) {
  iter++;
  int ret = iter;
  assert(s[ret].size() == 0);
  for(auto it : f[now]) {
    if(s[ret].count(it)) {
      s[ret].erase(it);
    } else {
      s[ret].insert(it);
    }
  }
  for(auto e : edge[now]) {
    if(e.first == prev) continue;
    int tmp = dfs(e.first, now);
    ans[e.second] = s[tmp].size();
    if(s[ret].size() < s[tmp].size()) {
      for(auto it : s[ret]) {
        if(s[tmp].count(it)) {
          s[tmp].erase(it);
        } else {
          s[tmp].insert(it);
        }
      }
      ret = tmp;
    } else {
      for(auto it : s[tmp]) {
        if(s[ret].count(it)) {
          s[ret].erase(it);
        } else {
          s[ret].insert(it);
        }
      }
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].emplace_back(b, i);
    edge[b].emplace_back(a, i);
  }
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    f[a].push_back(i);
    f[b].push_back(i);
  }
  dfs(1, -1);
  for(int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
