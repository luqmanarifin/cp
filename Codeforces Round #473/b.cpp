
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string s[N];
map<string, int> mp;
int id[N], a[N], cost[N];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    mp[s[i]] = i;
  }
  fill(cost, cost + N, 2e9);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    int v;
    cin >> v;
    while (v--) {
      int u;
      cin >> u;
      id[u] = i;
      cost[i] = min(cost[i], a[u]);
    }
  }
  long long ans = 0;
  while (m--) {
    string buf;
    cin >> buf;
    ans += cost[id[mp[buf]]];
  }
  cout << ans << endl;
  return 0;
}
