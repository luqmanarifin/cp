#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, s[N];
map<int, int> at;

int to[N];
vector<int> edge[N];
bool done[N];
vector<int> S;

void dfs(int now) {
  if (done[now]) return;
  done[now] = 1;
  S.push_back(now);
  dfs(to[now]);
  for (auto it : edge[now]) dfs(it);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    s[i] = a[i];
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++) {
    at[s[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    to[i] = at[a[i]];
    edge[at[a[i]]].push_back(i);
  }
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++) {
    S.clear();
    if (!done[i]) {
      dfs(i);
      ans.push_back(S);
    }
  }
  printf("%d\n", ans.size());
  for (auto i : ans) {
    printf("%d", i.size());
    for (auto j : i) {
      printf(" %d", j + 1);
    }
    printf("\n");
  }

  return 0;
}
