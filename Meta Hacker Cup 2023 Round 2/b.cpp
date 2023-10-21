#include <bits/stdc++.h>

using namespace std;

const long long p[] = {(long long)1e9 + 9, (long long)1e9 + 87, (long long)1e9 + 4207};
const long long mod[] = {(long long)2e9 + 89, (long long) 2e9 + 143, (long long)2e9 + 11};
const int K = 3;

// const long long p[] = {10};
// const long long mod[] = {(long long)2e9 + 89};
// const int K = 1;

#define Hash vector<long long>

bool same(Hash a, Hash b) {
  for (int i = 0; i < K; i++) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}

// actual logic code

const int N = 2e6 + 5;

int pre[2 * N], n;
vector<Hash> h[2], q[2];
vector<Hash> pwr, ipr;
long long ca[N], cb[N];

void add(int l, int r) {
  // printf("add %d %d\n", l, r);
  pre[l]++;
  pre[r + 1]--;
}

Hash mul(Hash a, Hash b) {
  Hash ret(K);
  for (int i = 0; i < K; i++) {
    ret[i] = (a[i] * b[i] % mod[i]);
  }
  return ret;
}

Hash add(Hash a, Hash b) {
  Hash ret(K);
  for (int i = 0; i < K; i++) {
    ret[i] = (a[i] + b[i]) % mod[i];
  }
  return ret;
}

Hash sub(Hash a, Hash b) {
  Hash ret(K);
  for (int i = 0; i < K; i++) {
    ret[i] = (a[i] - b[i] + mod[i]) % mod[i];
  }
  return ret;
}

Hash solve(int l, int r, int c) {
  if (l >= 2 * n) return solve(l % (2*n), r % (2*n), c);
  if (l >= n) return solve(l - n, r - n, c ^ 1);
  if (l / n == r / n) {
    Hash ret = h[c][r];
    if (l > 0) {
      int len = r - l + 1;
      ret = sub(ret, mul(h[c][l-1], pwr[len]));
    }
    return ret;
  }
  Hash lef = solve(l, n - 1, c);
  Hash rig = solve(0, r - n, c ^ 1);
  int len = r - n + 1;
  return add(rig, mul(lef, pwr[len]));
}

Hash reverse_solve(int l, int r, int c) {
  if (l >= 2 * n) return reverse_solve(l % (2*n), r % (2*n), c);
  if (l >= n) return reverse_solve(l - n, r - n, c ^ 1);
  if (l / n == r / n) {
    Hash ret = q[c][r];
    if (l > 0) {
      int len = r - l + 1;
      ret = mul(sub(ret, q[c][l-1]), ipr[l]);
    }
    return ret;
  }
  Hash lef = reverse_solve(l, n - 1, c);
  Hash rig = reverse_solve(0, r - n, c ^ 1);
  int len = n - l;
  return add(lef, mul(rig, pwr[len]));
}


long long pow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long ret = pow(a, b / 2, mod);
  ret = ret * ret % mod;
  if (b & 1) {
    ret = ret * a % mod;
  }
  return ret;
}

int main() {
  pwr.resize(2 * N);
  ipr.resize(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    pwr[i].resize(K);
    ipr[i].resize(K);
  }
  for (int k = 0; k < K; k++) {
    pwr[0][k] = ipr[0][k] = 1;
    long long inv = pow(p[k], mod[k] - 2, mod[k]);
    for (int i = 1; i < 2 * N; i++) {
      pwr[i][k] = pwr[i-1][k] * p[k] % mod[k];
      ipr[i][k] = ipr[i-1][k] * inv % mod[k];
    }
  }
  // puts("init");

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(pre, 0, sizeof(pre));

    scanf("%d", &n);
    h[0].resize(n);
    h[1].resize(n);
    q[0].resize(n);
    q[1].resize(n);
    for (int i = 0; i < n; i++) {
      h[0][i].resize(K);
      h[1][i].resize(K);
      q[0][i].resize(K);
      q[1][i].resize(K);
    }

    for (int i = 0; i < n; i++) scanf("%lld", ca + i);
    for (int i = 0; i < n; i++) scanf("%lld", cb + i);
    for (int k = 0; k < K; k++) {
      h[0][0][k] = (ca[0] % mod[k]);
      h[1][0][k] = (cb[0] % mod[k]);
      q[0][0][k] = (ca[0] % mod[k]);
      q[1][0][k] = (cb[0] % mod[k]);
      for (int i = 1; i < n; i++) {
        h[0][i][k] = (h[0][i-1][k] * p[k] + ca[i]) % mod[k];
        h[1][i][k] = (h[1][i-1][k] * p[k] + cb[i]) % mod[k];

        q[0][i][k] = (q[0][i-1][k] + ca[i] * pwr[i][k]) % mod[k];
        q[1][i][k] = (q[1][i-1][k] + cb[i] * pwr[i][k]) % mod[k];
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = i; j < n; j++) {
    //     printf("%d %d: a %lld\n", i, j, reverse_solve(i, j, 0)[0]);
    //     printf("%d %d: b %lld\n", i, j, reverse_solve(i, j, 1)[0]);
    //   }
    // }

    for (int i = 0; i < n; i++) {
      // printf("\nindex %d\n", i);
      if (ca[i] < cb[i]) {
        // a < b kiri
        {
          int r = i;
          int l = max(0, i - (n / 2 - 1));
          add(l, r);
        }

        // a < b kanan
        {
          if (i + 1 < n / 2) {
            int d = n / 2 - 1 - i;
            add(2 * n - d, 2 * n - 1);
          }
        }

        // a > b next round
        {
          int l = i + 1;
          int r = i + n / 2;
          add(l, r);
        }

      } else if (ca[i] > cb[i]) {

        // a > b kiri
        {
          if (i >= (n + 1) / 2) {
            int r = i - (n + 1) / 2;
            add(0, r);
          }
        }

        // a > b kanan
        {
          if (i + 1 < n) {
            int max_d = (n - 1 - i);
            int l = 2 * n - max_d;
            int r = min(2 * n - 1, l + n/2 - 1);
            add(l, r);
          }
        }

        // a < b next round
        {
          int l = i + 1 + (n + 1) / 2;
          int r = l + n/2 - 1;
          add(l, r);
        }

      } else {

        if (n % 2) {
          int d = i - n / 2;
          while (d < 0) d += 2 * n;

          for (int k = 0; k < 2; k++) {
            add(d, d);
            d = (d + n) % (2 * n);
          }
        }

      }
    }

    for (int i = 0; i < 2 * n; i++) {
      // printf("iterating %d\n", i);
      int lef_l = i;
      int lef_r = lef_l + n/2 - 1;
      int rig_l = i + (n + 1) / 2;
      int rig_r = rig_l + n/2 - 1;

      if (same(solve(lef_l, lef_r, 0), reverse_solve(rig_l, rig_r, 1))) {
        add(i, i);
      }

      if (same(solve(lef_l, lef_r, 1), reverse_solve(rig_l, rig_r, 0))) {
        add(i, i);
      }
    }
    for (int i = 1; i < 2 * n; i++) {
      pre[i] += pre[i-1];
    }
    int ans = -1;
    for (int i = 0; i < 2 * n; i++) {
      int here = pre[i];
      // printf("here %d: %d\n", i, here);
      if (here == n + 2) {
        ans = i;
        break;
      }
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
