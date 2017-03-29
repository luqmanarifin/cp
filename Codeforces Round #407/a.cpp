#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
long long s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  vector<long long> d;
  for (int i = 1; i < n; i++) d.push_back(i%2? abs(a[i] - a[i-1]) : -abs(a[i] - a[i-1]));
  long long sum = 0;
  for (int i = 0; i < d.size(); i++) {
    sum += d[i];
    s[i] = sum;
  }
  long long ans = -2e18;
  set<long long> cur;
  for (int i = d.size() - 1; i >= 0; i--) {
    cur.insert(s[i]);
    long long res = (i? s[i - 1] : 0);
    long long it = *(cur.begin());
    if (i % 2 == 0) {
      it = *(cur.rbegin());
    }
    res = it - res;
    if (i % 2 == 0) {
      ans = max(ans, res);
    } else {
      ans = max(ans, -res);
    }
  }
  cout << ans << endl;
  return 0;
}
