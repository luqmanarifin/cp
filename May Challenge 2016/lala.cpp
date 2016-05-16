#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const int MAGIC = 8660;
// 8660
// 12247
 
#define ull unsigned long long
 
int SIZE;
map<int, int> MP;
int sorted[N];
 
struct bin {
  bin() {
    a = new ull[SIZE];
    for(int i = 0; i < SIZE; i++) a[i] = 0;
  }
  ~bin() {
    delete[] a;
  }
  bin operator|(const bin& o) {
    bin ret;
    for(int i = 0; i < SIZE; i++) {
      ret.a[i] = (a[i] | o.a[i]);
    }
    return ret;
  }
  void operator=(const bin& o) {
    for(int i = 0; i < SIZE; i++) {
      a[i] = o.a[i];
    }
  }
  int count() {
    int ret = 0;
    for(int i = 0; i < SIZE; i++) {
      ret += __builtin_popcountll(a[i]);
    }
    return ret;
  }
  int find(int k) {
    int now = 0;
    for(int i = 0; i < SIZE; i++) {
      int cnt = __builtin_popcountll(a[i]);
      if(now + cnt >= k) {
        for(int j = 0; j < 64; j++) {
          if(a[i] & (1LL << j)) {
            if(++now == k) return i * 64 + j;
          }
        }
      }
      now += cnt;
    }
    return -1;
  }
  ull* a;
};
 
bin* dp[N / MAGIC + 5];
int e[N], f[N];
int num[N];
int n, q;
 
int cari(int l, int r, int k) {
  bin* ret = new bin();
  int from = l / MAGIC, to = r / MAGIC;
  int ff = (l == from * MAGIC? from : from + 1);
  int tt = (r == n - 1 || r == (to + 1) * MAGIC - 1? to : to - 1);
  for(int i = ff; i <= tt; i++) {
    *ret = *ret | *dp[i];
  }
  if(from == to) {
    for(int i = l; i <= r; i++) {
      ret->a[e[i]] |= (1LL << f[i]);
    }
  } else {
    if(ff != from) {
      int fto = (from + 1) * MAGIC;
      for(int i = l; i < fto; i++) {
        ret->a[e[i]] |= (1LL << f[i]);
      }
    }
    if(tt != to) {
      for(int i = to * MAGIC; i <= r; i++) {
        ret->a[e[i]] |= (1LL << f[i]);
      }
    }
  }
  int ans = (ret->count() < k? -1 : sorted[ret->find(k)]);
  delete ret;
  return ans;
}
 
int main() {
  scanf("%d %d", &n, &q);
  set<int> all;
  for(int i = 0; i < n; i++) {
    scanf("%d", num + i);
    all.insert(num[i]);
  }
  int id = 0;
  for(auto it : all) {
    sorted[id] = it;
    MP[it] = id++;
  }
  SIZE = id / 64 + (id % 64? 1 : 0);
  
  for(int i = 0; i < N / MAGIC + 5; i++) {
    dp[i] = new bin();
  }
  for(int i = 0; i < n; i++) {
    e[i] = MP[num[i]] / 64;
    f[i] = MP[num[i]] % 64;
  }
  for(int i = 0; i < n; i++) {
    dp[i / MAGIC]->a[e[i]] |= (1LL << f[i]);
  }
  
  
  int ans = 0;
  while(q--) {
    int a, b, c, d, k;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    long long l = (1LL * a * max(ans, 0) + b) % n;
    long long r = (1LL * c * max(ans, 0) + d) % n;
    if(l > r) swap(l, r);
    ans = cari(l, r, k);
    printf("%d\n", ans);
  }
  return 0;
}