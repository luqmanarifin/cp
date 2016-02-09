#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> p[N];
long long sum[N];

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  long long ans = 0;
  sort(p + 1, p + 1 + n);
  for(int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + p[i].second;
  }
  for(int i = 1; i <= n; i++) {
    int at = lower_bound(p + 1, p + 1 + n, make_pair(p[i].first + d, -1)) - p;
    at--;
    ans = max(ans, sum[at] - sum[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
