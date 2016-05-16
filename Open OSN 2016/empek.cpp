#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct BIT {
  BIT() {
    bit.assign(N, 0);
  }
  void update(int i, long long val) {
    for(; i < N; i |= i + 1) {
      bit[i] += val;
    }
  }
  long long find(int i) {
    long long ret = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1) {
      ret += bit[i];
    }
    return ret;
  }
  vector<long long> bit;
};

char junk[N], s[N];

int main() {
  int n;
  scanf("%s %d %s", junk, &n, s + 1);
  BIT a, b, c;
  for(int i = 1; i <= n; i++) {
    if(s[i] == '1') {
      a.update(i, 1);
    } else if(s[i] == '2') {
      b.update(i, a.find(i));
    } else {
      c.update(i, b.find(i));
    }
  }
  printf("%lld\n", c.find(N - 1));
  return 0;
}