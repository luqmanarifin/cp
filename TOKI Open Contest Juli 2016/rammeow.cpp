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
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  vector<tuple<int, int, int>> que;
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    que.emplace_back(r, l, i);
  }
  sort(que.begin(), que.end());
  map<int, int> last;
  bit b;
  int p = 0, l = 1;
  for (int r = 1; r <= n; r++) {
    if (last.count(a[r])) {
      l = max(l, last[a[r]] + 1);
    }
    //printf("%d %d\n", l, r);
    //for (int i = 1; i <= n; i++) printf("%lld ", b.find(i, i)); printf("\n");
    b.add(l, r, 1);
    while (p < que.size() && get<0>(que[p]) == r) {
      ans[get<2>(que[p])] = b.find(get<1>(que[p]), r);
      p++;
    }
    last[a[r]] = r;
  }
  //for (int i = 1; i <= n; i++) printf("%lld ", b.find(i, i)); printf("\n");
  for (int i = 1; i <= q; i++) {
    printf("%lld\n", ans[i]);
  }
  
  return 0;
}
