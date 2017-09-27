#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p.emplace_back(b, a);
  }
  sort(p.begin(), p.end());
  multiset<int> s;
  for (auto i : p) {
    int a, b;
    tie(b, a) = i;
    auto it = s.lower_bound(a);
    if (it != s.begin()) {
      it--;
      s.erase(it);
    }
    s.insert(a);
  }
  cout << s.size() << endl;
  return 0;
}
