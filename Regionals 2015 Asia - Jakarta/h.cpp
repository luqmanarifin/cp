#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const int BIG = 1e6 + 5;
const long long inf = 1e18;

int p[N], q[N];
vector<int> pos, a;

long long dp[N];
int clef[BIG], slef[BIG], crig[BIG], srig[BIG];

int id(int val) {
  return lower_bound(pos.begin(), pos.end(), val) - pos.begin();
}

long long find(int l, int r, int center) {
  if (r < 0) return 0;
  assert(l <= center && center <= r);
  long long ret = slef[center] - slef[l] - 1LL * (l - 1 >= 0? clef[l - 1] : 0) * (center - l)
  + srig[center] - srig[r] - 1LL * (r + 1 < BIG? crig[r + 1] : 0) * (r - center);
  //printf("%d %d %d %lld\n", l, r, center, ret);
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    pos.clear();
    a.clear();
    fill(dp, dp + N, inf);
    memset(clef, 0, sizeof(clef));
    memset(slef, 0, sizeof(slef));
    memset(crig, 0, sizeof(crig));
    memset(srig, 0, sizeof(srig));
    
    int n, m, A, B;
    scanf("%d %d %d %d", &n, &m, &A, &B);
    
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      v++;
      a.push_back(v);
      pos.push_back(v);
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d %d", p + i, q + i);
      p[i]++;
      clef[p[i]]++;
      crig[p[i]]++;
      ans += 1LL * q[i] * B;
      pos.push_back(p[i]);
    }
    pos.push_back(0);
    sort(pos.begin(), pos.end());
    pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
    sort(a.begin(), a.end());
    
    //puts("beby");
    for (int i = 1; i < BIG; i++) {
      clef[i] += clef[i - 1];
      slef[i] = slef[i - 1] + clef[i - 1];
    }
    for (int i = BIG - 2; i >= 0; i--) {
      crig[i] += crig[i + 1];
      srig[i] = srig[i + 1] + crig[i + 1];
    }
    //puts("DP done");
    
    dp[0] = 0;
    for (int it = 0; it < a.size(); it++) {
      int now = id(a[it]);
      int bef = 1;
      int aft = pos.size() - 1;
      //printf("lala %d %d %d\n", bef, now, aft);
      for (int j = aft; j >= bef; j--) {
        for (int i = j; i >= bef; i--) {
          int l = pos[i], r = pos[j];
          //printf("%d %d %d\n", l, r, a[it]);
          while (r - l > 3) {
            int lf = l + (r - l) / 3;
            int rf = r - (r - l) / 3;
            long long val_lf = 1LL * abs(a[it] - lf) * A + find(pos[i], pos[j], lf) * B;
            long long val_rf = 1LL * abs(a[it] - rf) * A + find(pos[i], pos[j], rf) * B;
            if (val_lf <= val_rf) {
              r = rf;
            } else {
              l = lf;
            }
          }
          long long add = inf;
          for (int k = l; k <= r; k++) {
            add = min(add, 1LL * abs(a[it] - k) * A + find(pos[i], pos[j], k) * B);
          }
          long long cur = dp[i - 1] + add;
          if (cur < dp[j]) {
            dp[j] = cur;
            //printf("%d di %d help %d jadi %lld\n", it, a[it], pos[j], dp[j]);
          }
        }
      }
    }
    printf("Case #%d: %lld\n", tt, ans + dp[pos.size() - 1]);
  }
 
  return 0;
}
