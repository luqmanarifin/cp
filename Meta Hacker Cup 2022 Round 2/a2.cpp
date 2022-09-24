#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int ITER = 16e6;
const long long ONE = 1e9;
const long long TWO = 2e9;
const long long MOD[] = {TWO + 143, ONE + 4207, TWO + 2153, ONE + 87, ONE + 9};
const int D = 1;

int x[N], n;

long long p[N], invp[N][D];
bitset<ITER> is;
long long meow[N][D];

long long power(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2, mod);
  tmp = tmp * tmp % mod;
  if (b % 2) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a, long long mod) {
  return power(a, mod - 2, mod);
}

void add_mul(int j, int i, long long val) {
  for (; i <= n; i |= i + 1) {
    meow[i][j] *= val;
    meow[i][j] %= MOD[j];
  }
}

vector<long long> find_mul(int i) {
  int ori_i = i;
  vector<long long> result(D);
  for (int j = 0; j < D; j++) {
    long long ret = 1;
    for (i = ori_i; i >= 0; i = (i & (i + 1)) - 1) {
      ret *= meow[i][j];
      ret %= MOD[j];
    }
    result[j] = ret;
  }
  return result;
}

vector<long long> find_mul(int l, int r) {
  vector<long long> result;
  auto rig = find_mul(r);
  auto lef = find_mul(l - 1);
  for (int j = 0; j < D; j++) {
    auto ret = rig[j] * inv(lef[j], MOD[j]) % MOD[j];
    result.push_back(ret);
  }
  // printf("find_mul %d %d: ", l, r); for (int j = 0; j < D; j++) printf("%lld ", result[j]); printf("\n");
  return result;
}

int main() {
  int cnt_prime = 0;
  is[0] = is[1] = 1;
  for (int i = 2; i < ITER; i++) {
    if (is[i]) continue;
    cnt_prime++;
    if (cnt_prime >= N) break;
    p[cnt_prime] = i;
    for (int j = 0; j < D; j++) {
      invp[cnt_prime][j] = inv(i, MOD[j]);
    }
    for (long long j = (long long) i * i; j < ITER; j += i) {
      is[j] = 1;
    }
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);

    for (int j = 0; j < D; j++) {
      for (int i = 0; i <= n; i++) {
        meow[i][j] = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", x + i); 
      for (int j = 0; j < D; j++) {
        add_mul(j, i, p[x[i]]);
      }
    }
    find_mul(1, 5);
    int ans = 0;
    int q;
    scanf("%d", &q);
    for (int qq = 1; qq <= q; qq++) {
      int c, l, r;
      scanf("%d %d %d", &c, &l, &r);
      if (c == 1) {
        for (int j = 0; j < D; j++) {
          add_mul(j, l, invp[x[l]][j]);
          add_mul(j, l, p[r]);
        }
        x[l] = r;
      } else {
        int len = r - l + 1;
        if (len % 2 == 0) continue;
        int mid = (l + r) >> 1;
        bool ok = 0;
        for (int i = mid - 1; i <= mid; i++) {
          auto lef = find_mul(l, i);
          auto rig = find_mul(i + 1, r);

          vector<long long> val(D);
          for (int j = 0; j < D; j++) {
            if (i == mid) {
              val[j] = lef[j] * inv(rig[j], MOD[j]) % MOD[j];
            } else {
              val[j] = inv(lef[j], MOD[j]) * rig[j] % MOD[j];
            }
          }
          bool same = 1;
          for (int j = 1; j < D; j++) {
            if (val[j] != val[j-1]) {
              same = 0;
            }
          }
          if (!same) continue;

          if (val[0] < ITER && !is[val[0]]) {
            ok = 1;
          }
        }
        if (ok) {
          ans++;
        }
        // printf("end of tc %d\n\n", qq);
      }
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
