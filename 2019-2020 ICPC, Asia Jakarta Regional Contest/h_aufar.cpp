#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> x[N];
int biggest[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    if (p > q) swap(p, q);
    x[i] = make_pair(p, q);
    ans = max(ans, 1LL * p * q);
  }
  sort(x, x + n);
  biggest[n-1] = x[n-1].second;
  for (int i = n - 2; i >= 0; i--) {
    biggest[i] = max(biggest[i + 1], x[i].second);
  }
  for (int i = 0; i + 1 < n; i++) {
    int p = x[i].first;
    int q = x[i].second;
    ans = max(ans, 2LL * p * min(q, biggest[i + 1]));
  }
  cout << ans / 2 << (ans % 2 ? ".5" : ".0") << endl;
  return 0;
}
