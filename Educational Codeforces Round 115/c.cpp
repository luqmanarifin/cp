#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
map<int, int> cnt;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt.clear();

    int n;
    scanf("%d", &n);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);   
      tot += a[i];
      cnt[a[i]]++;
    }
    if ((tot * 2) % n) {
      printf("0\n");
      continue;
    }
    long long p = (tot * 2) / n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long target = p - a[i];
      cnt[a[i]]--;
      ans += cnt[target];
    }
    printf("%lld\n", ans);
  }

  return 0;
}
