
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];
int par[26];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < 26; i++) par[i] = i;
  vector<pair<int, int>> ans;
  int n;
  scanf("%d %s %s", &n, a, b);
  for (int i = 0; i < n; i++) {
    a[i] -= 'a';
    b[i] -= 'a';
    if (find(a[i]) != find(b[i])) {
      merge(a[i], b[i]);
      ans.emplace_back(a[i], b[i]);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%c %c\n", it.first + 'a', it.second + 'a');
  return 0;
}
