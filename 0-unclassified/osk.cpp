#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

vector<long long> a = {-17, -10, -3, 1, 3, 5, 7, 9, 10};
bool vis[1 << 9];
long long mn[1 << 9], mx[1 << 9];

void dfs(int mask) {
  if (vis[mask]) return;
  vis[mask] = 1;
  mn[mask] = inf, mx[mask] = -inf;
  for (int i = ((mask - 1) & mask); i > 0; i = ((i - 1) & mask)) {
    dfs(i);
    dfs(mask ^ i);

    mn[mask] = min(mn[mask], mx[i] * mx[mask ^ i] + min(mx[i], mx[mask ^ i]));
    mn[mask] = min(mn[mask], mn[i] * mx[mask ^ i] + min(mn[i], mx[mask ^ i]));
    mn[mask] = min(mn[mask], mx[i] * mn[mask ^ i] + min(mx[i], mn[mask ^ i]));
    mn[mask] = min(mn[mask], mn[i] * mn[mask ^ i] + min(mn[i], mn[mask ^ i]));

    mx[mask] = max(mx[mask], mx[i] * mx[mask ^ i] + max(mx[i], mx[mask ^ i]));
    mx[mask] = max(mx[mask], mn[i] * mx[mask ^ i] + max(mn[i], mx[mask ^ i]));
    mx[mask] = max(mx[mask], mx[i] * mn[mask ^ i] + max(mx[i], mn[mask ^ i]));
    mx[mask] = max(mx[mask], mn[i] * mn[mask ^ i] + max(mn[i], mn[mask ^ i]));
  }
}

int main() {
  for (int i = 0; i < a.size(); i++) vis[1 << i] = 1, mn[1 << i] = mx[1 << i] = a[i];
  int all = (1 << a.size()) - 1;
  dfs(all);
  cout << mx[all] << endl; 
  return 0;
}