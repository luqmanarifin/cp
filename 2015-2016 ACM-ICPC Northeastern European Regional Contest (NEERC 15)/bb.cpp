#include <bits/stdc++.h>

using namespace std;

unsigned long long val[66];

int cek(int len, unsigned long long n, unsigned long long mod) {
  unsigned long long cur = (-n) & mod;
  for (int i = 0; i < len; ++i) if (n & (1ULL << i)) {
    cur += val[i];
    cur &= mod;
  }
  return !cur;
}

int main() {
  unsigned long long cur = 1;
  for (int i = 0; i < 64; ++i) {
    val[i] = cur;
    cur *= 10;
  }
  vector<unsigned long long> ans;
  ans.push_back(1);
  for (int len = 2; len <= 64; ++len) {
    cur = (1ULL << (len-1));
    unsigned long long mod = (1ULL << len) - 1;
    int last = ans.size();
    ans.push_back(cur);
    //cerr << cek(len, cur, mod) << endl;
    for (int j = 0; j < last; ++j) {
      long long add = ans[j] + cur;
      add &= mod;
      if (cek(len, add, mod))
        ans.push_back(add);
    }
    cout << len << " " << ans.size() << endl;
  }
  return 0;
}