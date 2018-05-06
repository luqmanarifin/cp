
#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> solve(long long a, long long b) {
  if (a == 0 || b == 0) return {a, b};
  if (a >= 2 * b) {
    return solve(a % (2 * b), b);
  }
  if (b >= 2 * a) {
    return solve(a, b % (2 * a));
  }
  return {a, b};
}

int main() {
  long long a, b;
  cin >> a >> b;
  auto ans = solve(a, b);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}
