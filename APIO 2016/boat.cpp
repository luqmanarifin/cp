#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 505;

int a[N], b[N];
vector<long long> bit;
vector<long long> coef[N];
vector<long long> self[N];

long long get(int i) {
  long long ret = 0;
  for(; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret % mod;
}

void update(int i, long long val) {
  for(; i < bit.size(); i |= i + 1) {
    bit[i] += val;
    bit[i] %= mod;
  }
}

long long power(long long u, long long v) {
  if(v == 0) return 1;
  long long temp = power(u, v / 2);
  temp = temp * temp % mod;
  if(v & 1) temp = temp * u % mod;
  return temp;
}

long long inv(long long u) {
  return power(u, mod - 2);
}

long long c(int n, int k) {
  if(n < k || n < 0 || k < 0) return 0;
  k = min(k, n - k);
  long long ret = 1;
  for(int i = 0; i < k; i++) {
    ret = ret * (n - i) % mod;
    ret = ret * inv(i + 1) % mod;
  }
  return ret;
}

main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  set<pair<int, int>> all;
  for(int i = 0; i < n; i++) {
    vector<pair<int, int>> del, ins;
    int l = a[i];
    int r = b[i];
    for(auto it : all) {
      pair<int, int> ot = it;
      int p = ot.first;
      int q = ot.second;
      int lef = max(l, p);
      int rig = min(r, q);
      if(lef <= rig) {
        del.push_back(ot);
        while(p <= q && l <= r) {
          if(p < l) {
            ins.emplace_back(p, l - 1);
            p = l;
          } else if(l < p) {
            ins.emplace_back(l, p - 1);
            l = p;
          } else {
            int t = min(r, q);
            ins.emplace_back(l, t);
            l = p = t + 1;
          }
        }
        if(p <= q) ins.emplace_back(p, q);
      }
      if(l > r) break;
    }
    if(l <= r) ins.emplace_back(l, r);
    for(auto it : del) all.erase(it);
    for(auto it : ins) all.insert(it);
  }
  //for(auto it : all) printf("wew %d %d\n", it.first, it.second);
  vector<pair<int, int>> id;
  for(auto it : all) id.push_back(it);
  bit.resize(id.size());
  for(int i = 0; i < n; i++) {
    coef[i].resize(id.size());
    self[i].resize(id.size());
  }
  for(int j = 0; j < id.size(); j++) {
    int len = id[j].second - id[j].first + 1;
    coef[1][j] = c(len, 2);
    for(int i = 2; i < n; i++) {
      coef[i][j] = coef[i - 1][j] * (i + len - 1) % mod;
      coef[i][j] = coef[i][j] * inv(i + 1) % mod;
    }
  }
  
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int l = a[i];
    int r = b[i];
    int p = lower_bound(id.begin(), id.end(), make_pair(l, -1LL)) - id.begin();
    vector<tuple<int, long long, long long>> add;
    while(p < id.size() && id[p].second <= r) {
      int len = id[p].second - id[p].first + 1;
      long long bit = get(p - 1);
      add.emplace_back(p, (bit * len + len) % mod, (bit + 1) % mod);
      p++;
    }
    for(auto it : add) {
      int at; long long sum, own;
      tie(at, sum, own) = it;
      update(at, sum);
      ans += sum;
      ans %= mod;
      for(int j = 0; j < i; j++) {
        ans += self[j][at] * coef[i - j][at];
        ans %= mod;
      }
      self[i][at] += own;
      self[i][at] %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}