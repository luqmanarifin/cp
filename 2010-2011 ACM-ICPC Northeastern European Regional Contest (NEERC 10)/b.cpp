#include <bits/stdc++.h>

using namespace std;

const string NAME = "binary";

const int L = 10;

struct F {
  int to[L];
  F() {
    for (int i = 0; i < L; ++i)
      to[i] = i;
  }
  F operator+(F p) {
    F ret;
    for (int i = 0; i < L; ++i) {
      ret.to[i] = p.to[to[i]];
    }
    return ret;
  }
  F operator*(long long p) {
    F b = *this;
    F r;
    for (; p; p >>= 1, b = b + b)
      if (p & 1)
        r = r + b;
    return r;
  }
};

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  F f[L];
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      int x;
      scanf("%d", &x);
      f[j].to[i] = x;
    }
  }
  long long a,b;
  cin >> a >> b;
  if (a == b) {
    cout << b <<endl;
    return 0;
  }
  vector<int> ans;
  long long now = b;
  while (now) {
    ans.push_back(0);
    now /= 10;
  }
  int n = ans.size();
  long long cur = 1;
  for (int i = 0; i < n; ++i, cur *= 10) {
    long long c = a + 1, d = b;
    F depan, belakang;
    while (c <= d) {
      if ((c % (cur * 10)) == 0) break;
      long long to = (c + cur - 1) / cur;
      to *= cur;
      if (to == c)
        to += cur;
      --to;
      to = min(to, d);
      int dig = (c/cur) % 10;
      depan = depan + f[dig] * (to - c + 1);
      c = to+1;
    }
    while (c <= d) {
      if ((d % (cur * 10)) == (cur * 10 - 1)) break;
      long long to = d / cur;
      to *= cur;
      to = max(to, c);
      int dig = (d/cur) % 10;
      belakang = f[dig] * (d - to + 1) + belakang;
      d = to-1;
    }
    
    F tengah;
    for (int j = 0; j < L; ++j) {
      tengah = tengah + f[j] * cur;
    }
    if (c <= d) {
      long long cnt = (d + 1 - c) / (cur * 10);
      depan = depan + tengah * cnt;
    }
    depan = depan + belakang;
    ans[n-1-i] = depan.to[(a / cur) % 10];    
  }
  bool zero = 1;
  for (int i = 0; i < n; ++i) {
    if (zero && ans[i] == 0) continue;
    printf("%d", ans[i]);
    if (ans[i] > 0) zero = 0;
  }
  if (zero) printf("0");
  printf("\n");
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
