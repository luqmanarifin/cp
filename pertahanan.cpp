#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long bit[N];
long long desc[N];
long long asc[N];

void add(long long* a, int at, int val) {
  for(; at < N; at |= at + 1) {
    a[at] += val;
  }
}

long long find(long long* a, int at) {
  int ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += a[at];
  }
  return ret;
}

long long count(long long* a, int l, int r) {
  return find(a, r) - find(a, l - 1);
}

int main() {
  int q, n = 2000000;
  scanf("%d", &q);
  set<int> cok;
  cok.insert(0);
  cok.insert(n + 1);

  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int at;
      scanf("%d", &at);
      add(desc, at, N - at);
      add(asc, at, at);
      add(bit, at, 1);
    } else if(t == 2) {
      int at;
      scanf("%d", &at);
      add(desc, at, -(N - at));
      add(asc, at, -at);
      add(bit, at, -1);
    } else {
      int at;
      scanf("%d", &at);
      auto it = cok.lower_bound(at);
      int tr = *it;
      it--;
      int tl = *it;
      
      long long lef = count(desc, tl + 1, at);
      long long rig = count(asc, at, tr - 1);
      
      long long ans = lef - 1LL * count(bit, tl + 1, at) * (N - at);
      ans += rig - 1LL * count(bit, at, tr - 1) * at;
      
      printf("%lld\n", ans);
      
      cok.insert(at);
    }
  }
  
  return 0;
}
