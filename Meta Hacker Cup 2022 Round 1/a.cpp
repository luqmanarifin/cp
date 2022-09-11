#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long P[] = {(long long)1e9 + 9, (long long)1e9 + 87};
const long long MOD[] = {(long long)2e9 + 1851, (long long)2e9 + 2153};

long long POW[2][N];

long long power(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2, mod);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a, long long mod) {
  return power(a, mod - 2, mod);
}

pair<long long, long long> compute(vector<int> a) {
  long long now[] = {0, 0};
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < 2; j++) {
      now[j] += a[i] * POW[j][i] % MOD[j];
      now[j] %= MOD[j];
    }
  }
  return make_pair(now[0], now[1]);
}

int main() {
  long long INV[] = {inv(P[0], MOD[0]), inv(P[1], MOD[1])};
  POW[0][0] = POW[1][0] = 1;
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i < N; i++) {
      POW[j][i] = POW[j][i-1] * P[j] % MOD[j];
    }
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    auto valb = compute(b);
    auto vala = compute(a);
    auto ori = vala;
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (vala == valb) {
        s.insert(i);
      }
      long long cur[] = {vala.first, vala.second};
      for (int j = 0; j < 2; j++) {
        cur[j] = (cur[j] - a[i] + MOD[j]) % MOD[j];
        cur[j] = cur[j] * INV[j] % MOD[j];
        cur[j] += a[i] * POW[j][n-1] % MOD[j];
        cur[j] %= MOD[j];
      }
      vala = {cur[0], cur[1]};
    }
    assert(ori == vala);
    bool ok = 0;
    if (n == 2) {
      if (s.count(k % 2)) {
        ok = 1;
      }
    } else {
      if (k == 0) {
        if (s.count(0)) {
          ok = 1;
        }
      } else if (k == 1) {
        for (int i = 1; i < n; i++) {
          if (s.count(i)) {
            ok = 1;
          }
        }
      } else {
        if (s.size() > 0) {
          ok = 1;
        }
      }
    }
    printf("Case #%d: %s\n", tt, ok? "YES" : "NO");
    cerr << tt << " out of " << t << " done!" << endl;
  }

  return 0;
}
