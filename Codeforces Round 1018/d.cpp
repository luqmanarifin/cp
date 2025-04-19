#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e9;

map<int, int> cnt, cnt_sum;
int x[N], y[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt.clear();
    cnt_sum.clear();

    int n;
    scanf("%d", &n);
    long long sum_y = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", x + i, y + i);
      cnt[x[i]]++;
      cnt_sum[x[i] + y[i]]++;
    }

    int ans_x = 0, ans_y = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[x[i]] % 2) {
        ans_x = x[i];
      }
    }
    for (int i = 0; i < n; i++) {
      int sum = x[i] + y[i];
      if (cnt_sum[sum] % 2) {
        ans_y = sum - ans_x;
      }
    }
    printf("%d %d\n", ans_x, ans_y);
  }

  return 0;
}
