#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  multiset<int> out, in;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    out.insert(a + b);
    in.insert(a);
  }
  int ans = 0;
  for (auto t : out) {
    auto it = in.lower_bound(t);
    if (it != in.end() && *it <= t + m) {
      ans++;
      in.erase(it);
    }
  }
  cout << ans << endl;
  return 0;
}