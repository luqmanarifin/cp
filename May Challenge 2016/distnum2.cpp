#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define ull unsigned long long

int SIZE;
map<int, int> MP;
int sorted[N];

struct bin {
  bin() {
    a.resize(SIZE, 0);
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
  vector<ull> a;
};

struct segtree {
  segtree(int n, vector<int> num) : n(n), num(num) {
    //puts("allocating");
    a.resize((n << 1) + 10);
    //puts("done");
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if(l == r) {
      a[p].a[num[l] / 64] |= (1LL << (num[l] % 64));
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = a[p + p] | a[p + p + 1];
  }
  int find(int l, int r, int k) {
    bin ret = find(1, 0, n - 1, l, r);
    if(ret.count() < k) return -1;
    return sorted[ret.find(k)];
  }
  bin find(int p, int l, int r, int ll, int rr) {
    if(ll == l && r == rr) return a[p];
    int mid = (l + r) >> 1;
    bin ret;
    if(ll <= mid) {
      ret = ret | find(p + p, l, mid, ll, min(rr, mid));
    }
    if(mid < rr) {
      ret = ret | find(p + p + 1, mid + 1, r, max(mid + 1, ll), rr);
    }
    return ret;
  }
  vector<int> num;
  int n;
  vector<bin> a;
};

int num[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", num + i);
    MP[num[i]];
  }
  int id = 0;
  for(auto it : MP) {
    sorted[id] = it.first;
    MP[it.first] = id++;
  }
  SIZE = id / 64 + (id % 64? 1 : 0);
  
  vector<int> arr;
  for(int i = 0; i < n; i++) {
    arr.push_back(MP[num[i]]);
  }
  
  segtree seg(n, arr);
  
  int ans = 0;
  while(q--) {
    int a, b, c, d, k;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    long long l = (1LL * a * max(ans, 0) + b) % n;
    long long r = (1LL * c * max(ans, 0) + d) % n;
    if(l > r) swap(l, r);
    ans = seg.find(l, r, k);
    printf("%d\n", ans);
  }
  return 0;
}