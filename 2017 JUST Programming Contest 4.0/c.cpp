#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

pair<int, int> a[N];
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i].first), a[i].second = i;
    sort(a, a+n);
    for (int i = 0, j = n-1; i < n; i++) {
      while (j >= 0 && (i == j || (a[i].first + a[j].first) >= mod)) j--;
      int bg = n-1;
      if (bg == i) bg--;
      ans[a[i].second] = (a[i].first + a[bg].first) % mod;
      if (j >= 0 && j != i)
        ans[a[i].second] = max(ans[a[i].second], (a[i].first + a[j].first) % mod);
    }
    for (int i = 0; i < n; i++) {
      printf("%d%c", ans[i], " \n"[i == n-1]);
    }
  }
  return 0;
}
