#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18 + 1e17;
const int N = 1e5 + 5;

#define pii pair<long long, long long>
#define b first
#define c second

long long cross(pii l, pii r) {
  return l.b * r.c - l.c * r.b;
}

long long dot(pii l, pii r) {
  return l.b * r.b + l.c * r.c;
}

bool cmp(pair<pii, int> l, pair<pii, int> r) {
  long long crs = cross(l.b, r.b);
  if(crs == 0) {
    return dot(l.b, l.b) < dot(r.b, r.b);
  }
  return crs > 0;
}

int ans[N];
pii p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<pair<pii, int>> num;
    for(int i = 0; i < n; i++) {
      scanf("%lld %lld", &p[i].b, &p[i].c);
      num.push_back({p[i], 0});
    }
    for(int i = 1; i <= q; i++) {
      long long u, v;
      scanf("%lld %lld", &u, &v);
      num.push_back({{u, v}, i});
    }
    sort(num.begin(), num.end(), cmp);
    int pt = -1;
    long long best = -inf;
    for(int i = 0; i < n; i++) {
      long long cur = dot(num[0].b, p[i]);
      if(cur > best) {
        best = cur;
        pt = i;
      }
    }
    for(auto it : num) {
      pii now = it.b;
      int id = it.c;
      while(dot(now, p[(pt + 1) % n]) > dot(now, p[pt])) {
        pt = (pt + 1) % n;
      }
      //printf("nyam %lld %lld %d\n", now.b, now.c, pt);
      if(id) {
        ans[id] = dot(now, p[pt]);
      }
    }
    for(int i = 1; i <= q; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  
  return 0;
}
