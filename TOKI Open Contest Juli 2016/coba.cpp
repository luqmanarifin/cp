#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct bit {
  bit() {
    val.assign(N, 0);
    sum.assign(N, 0);
  }
  void add(int l, int r, int v) {
    add_pre(l, v, -1LL * l * v);
    add_pre(r + 1, -v, 1LL * (r + 1) * v);
  }
  void add_pre(int i, long long v, long long s) {
    for (; i < N; i |= i + 1) {
      val[i] += v;
      sum[i] += s;
    }
  }
  long long find(int l, int r) {
    return find_pre(r) - find_pre(l - 1);
  }
  long long find_pre(int i) {
    long long v = 0, s = 0;
    int p = i;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      v += val[i];
      s += sum[i];
    }
    return (p + 1) * v + s;
  }
  vector<long long> val, sum;
};

int a[N];
long long ans[N];

int main() {
  bit b;
  b.add(7, 8, 100);
  for (int i = 0; i < 10; i++) {
    printf("%lld ", b.find(0, i));
  }
  
  return 0;
}
