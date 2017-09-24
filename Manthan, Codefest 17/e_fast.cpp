#include <bits/stdc++.h>

using namespace std;

// b - panjang - mask
long long pre[20][100][1 << 10];

int sample[100];
int b; 

// panjang - banyak ganjil
long long dp[70][11];

long long solve(long long lim) {
  if (lim == 0) return 0;
  int len = 0;
  while (lim > 0) {
    //cout << lim << endl;
    sample[len] = lim % b;
    lim /= b;
    len++;
  }
  //printf("len %d\n", len);
  reverse(sample, sample + len);
  //for (int i = 0; i < len; i++) printf("%d ", sample[i]); printf("\n");

  memset(dp, 0, sizeof(dp));
  dp[1][1] = b - 1;
  for (int i = 1; i < len; i++) {
    for (int j = 0; j <= b; j++) {
      if (j - 1 >= 0) dp[i + 1][j - 1] += dp[i][j] * j;
      if (j + 1 <= b) dp[i + 1][j + 1] += dp[i][j] * (b - j);
    }
  }
  long long ans = 0;
  for (int i = 1; i < len; i++) ans += dp[i][0];

  //cout << "digit kurang " << ans << endl;

  int mask = 0;
  for (int i = 0; i < len; i++) {
    for (int j = (i? 0 : 1); j < sample[i]; j++) {
      ans += pre[b][len - i - 1][mask ^ (1 << j)];
    }
    mask ^= (1 << sample[i]);
  }
  if (mask == 0) ans++;

  return ans;
}

int main() {
  for (int base = 2; base <= 10; base++) {
    pre[base][0][0] = 1;
    for (int i = 0; i < 70; i++) {
      for (int j = 0; j < (1 << base); j++) {
        for (int k = 0; k < base; k++) {
          pre[base][i + 1][j ^ (1 << k)] += pre[base][i][j];
        }
      }
    }
    //cout << base << endl;
  }
  //puts("precompute done");
  b = 2;
  //cout << solve(15) << endl;

  int q;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%d %lld %lld", &b, &l, &r);
    long long rig = solve(r);
    long long lef = solve(l - 1);
    //printf("lef rig %lld %lld\n", lef, rig);
    printf("%lld\n", rig - lef);
  }
  return 0;
}
