#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int n, s;
  vector<pair<int, int>> a;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a.emplace_back(u, v);
  }
  sort(a.begin(), a.end());
  long long now = s, ans = 0;
  for (int i = 0; i < n; i++) {
    now += a[i].first;
    ans += now - a[i].second;
  }
  cout << ans << endl;
  return 0;
}
