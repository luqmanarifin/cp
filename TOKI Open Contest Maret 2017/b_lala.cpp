#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

vector<int> edge[N];
int u[N], v[N];

map<pair<int, int>, int> cnt;

int find(int u, int v) {
  if (u > v) swap(u, v);
  return cnt[{u, v}];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int pt = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u[i], &v[i]);
    if (u[i] > v[i]) swap(u[i], v[i]);
    cnt[{u[i], v[i]}]++;
    edge[u[i]].push_back(v[i]);
    if (u[i] != v[i]) {
      edge[v[i]].push_back(u[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (u[i] != v[i]) {
      int val = find(u[i], v[i]);
      ans += 2LL * (edge[u[i]].size() - val) * (edge[v[i]].size() - val);
      ans += 1LL * (val - 1) * (val - 2);
      ans += 2LL * (val - 1) * (edge[u[i]].size() - val);
      ans += 2LL * (val - 1) * (edge[v[i]].size() - val);
    } else {
      ans += 1LL * (edge[u[i]].size() - 1) * (edge[v[i]].size() - 2);
    }
  }
  cout << ans << endl;
  return 0;
}
