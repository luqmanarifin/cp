#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 600;
const int N = 1e5 + 5;

long long val[MAGIC][N], sum[MAGIC][N];
long long a[N];
int cnt[MAGIC];

long long solve(int s, int d, int k) {
  if (d >= MAGIC) {
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
      ans += a[s + (i - 1) * d] * i;
    }
    return ans;
  }
  int r = s + (k - 1) * d;
  long long VAL = val[d][r] - (s - d >= 0? val[d][s - d] : 0);
  long long SUM = sum[d][r] - (s - d >= 0? sum[d][s - d] : 0);
  int cnt_lef = s / d;
  return VAL - SUM * cnt_lef;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int mod = 1; mod < MAGIC; mod++) {
      for (int i = 0; i < mod; i++) cnt[i] = 0;
      for (int i = 0; i < n; i++) {
        cnt[i % mod]++;
        sum[mod][i] = a[i] + (i - mod >= 0? sum[mod][i-mod] : 0);
        val[mod][i] = a[i] * cnt[i % mod] + (i - mod >= 0? val[mod][i-mod] : 0);
      }
    }
    for (int qq = 0; qq < q; qq++) {
      int s, d, k;
      scanf("%d %d %d", &s, &d, &k);
      s--;
      printf("%lld%c", solve(s, d, k), qq + 1 == q? '\n' : ' ');
    }
  }

  return 0;
}
