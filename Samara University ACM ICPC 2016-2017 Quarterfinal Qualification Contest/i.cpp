#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
bool sip[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ans = 1e9, p = -1;
  for (int i = 1; i <= n; i++) {
    int cur = 1 + edge[i].size();
    if (cur < ans) {
      ans = cur;
      p = i;
    }
  }
  sip[p] = 1;
  for (auto it : edge[p]) sip[it] = 1;
  for (int i = 1; i <= n; i++) printf("%d ", sip[i] ^ 1);
  return 0;
}
