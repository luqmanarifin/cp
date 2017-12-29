#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp;

int main() {
  int n;
  scanf("%d", &n);
  int mini = 2e9;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    mini = min(mini, v);
    mp[v].push_back(i);
  }
  int ans = 2e9;
  for (int i = 1; i < mp[mini].size(); i++) {
    ans = min(ans, mp[mini][i] - mp[mini][i-1]);
  }
  cout << ans << endl;
  return 0;
}
