
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int v;
    cin >> v;
    a[v]++;
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) ans = min(ans, a[i]);
  cout << ans << endl;
  return 0;
}
