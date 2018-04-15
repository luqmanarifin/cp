#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      b[i] = 1;
      sum += a[i];
    }
    int mm = m;
    m -= n;
    sort(a, a+n);
    priority_queue<pair<double, int> > pq;
    for (int i = 0; i < n; ++i) {
      pq.push(make_pair((double)a[i] * a[i] / b[i] - (double)a[i] * a[i]/(b[i]+1), i));
    }
    while (m--) {
      auto it = pq.top(); pq.pop();
      int i = it.second;
      ++b[i];
      pq.push(make_pair((double)a[i] * a[i] / b[i] - (double)a[i] * a[i]/(b[i]+1), i));
    }
    double ans = 0;
    double mu = (double)sum /mm, sum2 = 0;
    for (int i = 0; i < n; ++i) {
      sum2 += (double)a[i] * a[i] / b[i];
    }
    ans = (sum2 / mm - mu * mu);
    printf("Case #%d: %.20lf\n", tc, ans); 
  }
  return 0;
}
