
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    vector<int> d;
    for (int i = 1; i < n; i++) d.push_back(a[i] - a[i - 1]);
    sort(d.begin(), d.end());
    long long ans = 0;
    for (int i = 0; i < n - k; i++) ans += d[i];
    printf("%I64d\n", ans);
  }
  return 0;
}
