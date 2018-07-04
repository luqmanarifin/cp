#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int GROUP = 25;
const long long mod = 1e9 + 7;

long long bef[N][GROUP], aft[N][GROUP];
long long sbef[N][GROUP], saft[N][GROUP];
char junk[N];
int a[N];

int rmq[N][20];

void add(long long& at, long long val) {
  at += val;
  at %= mod;
}

long long get_bef(int l, int r, int group) {
  long long ret = sbef[r][group];
  if (l > 0) ret -= sbef[l-1][group];
  if (ret < 0) ret += mod;
  return ret;
}

long long get_aft(int l, int r, int group) {
  long long ret = saft[r][group];
  if (l > 0) ret -= saft[l-1][group];
  if (ret < 0) ret += mod;
  return ret;
}

int get_rmq(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return __gcd(rmq[l][g], rmq[r-(1<<g)+1][g]);
}

int main() {
  int n, K;
  scanf("%s %d %d", junk, &n, &K);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    rmq[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      rmq[i][j] = __gcd(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  // puts("rmq done");

  bef[0][0] = sbef[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < GROUP; j++) {
      if (j > 0) add(bef[i][j], sbef[i-1][j-1]);
      add(bef[i][j], bef[i-1][j]);

      sbef[i][j] = (sbef[i-1][j] + bef[i][j]) % mod;
    }
  }

  aft[n+1][0] = saft[n+1][0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < GROUP; j++) {
      if (j > 0) add(aft[i][j], saft[i+1][j-1]);
      add(aft[i][j], aft[i+1][j]);

      saft[i][j] = (saft[i+1][j] + aft[i][j]) % mod;
    }
  }

  for (int j = 0; j < GROUP; j++) {
    for (int i = 1; i < N; i++) {
      sbef[i][j] = (sbef[i-1][j] + bef[i][j]) % mod;
      saft[i][j] = (saft[i-1][j] + aft[i][j]) % mod;
    }
  }
  // puts("pre compute done");
  long long ans = 0;
  for (int st = 1; st <= n; st++) {
    int j = st;
    while (j <= n) {
      int gcd = get_rmq(st, j);
      int l = j, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (get_rmq(st, mid) == gcd) {
          l = mid;
        } else {
          r = mid - 1;
        }
        // printf("l r %d %d\n", l, r);
      }
      int til = l;

      for (int k = 0; k < K; k++) {
        long long ways = (bef[st-1][k] * get_aft(j + 1, til + 1, K - 1 - k)) % mod;
        ans += ways * gcd;
        ans %= mod;
      }
      // printf("range %d %d\n", st, j);

      j = til + 1;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
