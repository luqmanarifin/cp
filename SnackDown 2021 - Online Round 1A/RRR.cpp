#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      long long internal_win = max(0, mid - n + k);
      long long tot_win = internal_win * k;
      long long pos_win = 1LL * k * (k - 1) / 2;
      if (tot_win > pos_win) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    printf("%d\n", 2 * l);
  }

  return 0;
}
