#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    long long be = sum / n;
    long long ans = 0;
    long long now = 0;
    for (int i = 0; i < n; i++) {
      long long diff = a[i] - be;
      now += diff;
      ans += abs(now);
    }
    printf("Case #%d: %lld\n", tt, ans);
  }
  
  return 0;
}