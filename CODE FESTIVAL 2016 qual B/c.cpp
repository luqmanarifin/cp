#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p.emplace_back(a[i], 0);
  }
  for (int j = 0; j < m; j++) {
    scanf("%d", b + j);
    p.emplace_back(b[j], 1);
  }
  sort(p.begin(), p.end());
  long long ans = 0;
  int ada_a = 0, ada_b = 0;
  for (auto it : p) {
    if (it.second == 0) {
      ans += 1LL * (m + 1 - ada_b) * it.first;
      ada_a++;
    } else {
      ans += 1LL * (n + 1 - ada_a) * it.first;
      ada_b++;
    }
    //cout << "haha " << ans << endl;
  }
  cout << ans << endl;
  
  return 0;
}