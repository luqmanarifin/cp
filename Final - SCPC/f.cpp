#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 600;
const int N = 1e5 + 5;
const long long mod = 1e9 + 8;

int nim_pol;

vector<int> edge[N];
int nim[N], cnt[MAGIC];

long long hop[MAGIC][40], ans[MAGIC], tmp[MAGIC];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    memset(cnt, 0, sizeof(cnt));

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
    }
    nim_pol = 0;
    for (int i = 1; i <= n; i++) {
      set<int> s;
      for (auto it : edge[i]) {
        s.insert(nim[it]);
      }
      for (int v = 0; ; v++) {
        if (!s.count(v)) {
          nim[i] = v;
          nim_pol = max(nim_pol, nim[i]);
          break;
        }
      }
    }
    ++nim_pol;
    while (__builtin_popcount(nim_pol) != 1) nim_pol++;
    for (int i = 1; i <= n; i++) {
      cnt[nim[i]]++;
    }
    memset(hop, 0, sizeof(hop));
    for (int i = 0; i < nim_pol; i++) {
      hop[i][0] = cnt[i];
    }
    for (int bit = 0; bit + 1 < 40; bit++) {
      for (int i = 0; i < nim_pol; i++) {
        for (int j = 0; j < nim_pol; j++) {
          hop[i ^ j][bit + 1] += hop[i][bit] * hop[j][bit];
          hop[i ^ j][bit + 1] %= mod;
        }
      }
    }
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (int bit = 0; bit < 31; bit++) {
      if (k & (1 << bit)) {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < nim_pol; i++) {
          for (int j = 0; j < nim_pol; j++) {
            tmp[i ^ j] += ans[i] * hop[j][bit];
            tmp[i ^ j] %= mod;
          }
        }
        for (int i = 0; i < nim_pol; i++) {
          ans[i] = tmp[i];
        }
      }
    }
    long long tot = 0;
    for (int i = 1; i < nim_pol; i++) {
      tot += ans[i];
    }
    printf("%lld\n", tot % mod);
  }

  return 0;
}
