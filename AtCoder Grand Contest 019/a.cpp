#include <bits/stdc++.h>

using namespace std;

pair<long long, int> p[5];
long long n;

int main() {
  for (int i = 0; i < 4; i++) {
    long long a;
    cin >> a;
    p[i] = {a, 1 << i};
  }
  sort(p, p + 4);
  cin >> n;
  n *= 4;
  
  long long ans = 1e18;
  do {
    long long cur = n;
    long long cost = 0;
    for (int i = 0; i < 4; i++) {
      long long nums = cur / p[i].second;
      cur -= nums * p[i].second;
      cost += nums * p[i].first;
    }
    ans = min(ans, cost);
  } while (next_permutation(p, p + 4));
  cout << ans << endl;
  return 0;
}
