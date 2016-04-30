#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

set<int> s;

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    s.insert(num);
  }
  int ans = 0;
  for(auto it : s) {
    ans += s.count(it + d) && s.count(it - d);
  }
  cout << ans << endl;
  return 0;
}