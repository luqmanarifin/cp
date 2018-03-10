#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int inf = 2e9;

int n;

int main() {
  scanf("%d", &n);
  vector<pair<int, int>> add, sub;
  long long sum = 0, cap = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= b) {
      add.emplace_back(a, b);
    } else {
      sub.emplace_back(b, a);
    }
    sum += a;
    cap += a;
  }
  sort(add.begin(), add.end());
  sort(sub.begin(), sub.end());
  reverse(sub.begin(), sub.end());
  long long ans = 0;
  for (auto it : add) {
    if (sum > cap - it.first) {
      long long v = sum - cap + it.first;
      ans += v;
      cap += v;
    }
    cap += it.second - it.first;
  }
  for (auto it : sub) {
    if (sum > cap - it.second) {
      long long v = sum - cap + it.second;
      ans += v;
      cap += v;
    }
    cap += it.first - it.second;
  }
  cout << ans << endl;
  return 0;
}
