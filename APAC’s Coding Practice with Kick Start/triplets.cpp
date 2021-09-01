#include <bits/stdc++.h>

using namespace std;

const int N = 7005;
const int MAX = 2e5 + 5;

int a[N], cnt[MAX];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) cnt[a[j]]++;
      for (int j = i + 1; j < n; j++) {
        cnt[a[j]]--;

        if (a[i] == 0 && a[j] == 0) {
          ans += n - 1 - j;
          continue;
        }

        set<int> num;
        if (1LL * a[i] * a[j] < MAX) {
          num.insert(a[i] * a[j]);
        }  
        if (a[j] != 0 && a[i] % a[j] == 0) {
          num.insert(a[i] / a[j]);
        }
        if (a[i] != 0 && a[j] % a[i] == 0) {
          num.insert(a[j] / a[i]);
        }
        if (a[i] == 0 || a[j] == 0) {
          num.insert(0);
        }
        for (auto it : num) {
          ans += cnt[it];
        }
      }
    }
    printf("Case #%d: %lld\n", tt, ans);
  }

  return 0;
}
