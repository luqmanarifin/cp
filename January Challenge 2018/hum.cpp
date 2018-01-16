#include <bits/stdc++.h>

using namespace std;

set<pair<long long, long long>> s[20];

int main() {
  s[0].insert(make_pair(0, 1));
  for (int i = 0; i < 15; i++) {
    for (auto it : s[i]) {
      auto a = it.first;
      auto b = it.second;
      s[i + 1].insert(make_pair(a + b, b));
      s[i + 1].insert(make_pair(a, a + b + 1));
    }
  }
  cout << s[15].size() << endl;
  return 0;
}
