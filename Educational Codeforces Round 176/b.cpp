#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5005;
 
int a[N], at[N];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      p.emplace_back(a[i], i);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    long long sum = 0;
    for (int i = 0; i < k; i++) {
      sum += p[i].first;
    }
    long long sum1 = sum + p[k].first;
    long long ans = 0;
    if (k == 1) {
      for (int i = 1; i < n; i++) {
        ans = max(ans, (long long)a[0] + a[i]);
      }
      for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, (long long)a[i] + a[n - 1]);
      }
    } else {
      ans = sum1;
    }
    printf("%lld\n", ans);
  }
 
  return 0;
}