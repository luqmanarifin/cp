#include <bits/stdc++.h>

using namespace std;

const string NAME = "binary";

const int N = 1024;

long long val[N];

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int len = 1; len < 44; ++len) {
    long long mod = 1LL << (len+1);
    int mid = len/2, mid2 = len - mid;
    map<long long, int> mp;
    long long dua = 1, sep = 1;
    for (long long i = 0; i <= len; ++i) {
      val[i] = sep - dua;
      if (val[i] < 0) val[i] += mod;
      sep = sep * 10 % mod;
      dua += dua;
      if (dua >= mod) dua -= mod;
    }
    long long nmask = 1LL << mid;
    for (long long mask = 0; mask < nmask; ++mask) {
      long long tot = 0;
      for (int j = 0; j < mid; ++j) if (mask & (1LL << j)) {
        tot += val[j];
        if (tot >= mod)
          tot -= mod;
      }
      mp[tot]++;
    }
    nmask = 1LL << (mid2);
    for (long long mask = 0; mask < nmask; ++mask) {
      long long tot = 0;
      for (int j = 0; j < mid2; ++j) if (mask & (1LL << j)) {
        tot += val[mid+j];
        if (tot >= mod)
          tot -= mod;
      }
      long long inv = (mod - tot) % mod;
      if (inv < 0) inv += mod;
      ans += mp[inv];
    }
    cerr << len << " " << ans << endl;
  }
  
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
