#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int BIT = 20;
const int MAX_NUM = (1 << BIT);

int a[N], sum[N], n;
int best[MAX_NUM][2];

int solve(int bit) {
  int offset = (-1 ^ ((1 << (bit + 1)) - 1));
  for (int i = 1; i <= n; i++) {
    sum[i] = (a[i] & offset);
    sum[i] ^= sum[i-1];
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if ((a[i] & (1 << bit)) == 0) continue;
    int until = i;
    while (until + 1 <= n && (a[until + 1] & (1 << bit))) {
      until++;
    }
    for (int j = i - 1; j <= until; j++) {
      best[sum[j]][0] = best[sum[j]][1] = 0;
    }
    for (int j = i; j <= until; j++) {
      best[sum[j]][j % 2] = j;
    }
    for (int j = i; j <= until; j++) {
      int c = (j % 2) ^ 1;
      ret = max(ret, best[sum[j-1]][c] - j + 1);
    }

    i = until;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < BIT; i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;
  return 0;
}
