#include <bits/stdc++.h>

using namespace std;

#define int long long

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

long long ans[N];
int n;
pii p[N];

void entry(vector<pair<pii, int>> num) {
  sort(num.begin(), num.end(), cmp);
  //("PART");
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
    //printf("%lld %lld\n", now.b, now.c);
    while(dot(now, p[(pt + 1) % n]) > dot(now, p[pt])) {
      pt = (pt + 1) % n;
    }
    //printf("nyam %lld %lld %d\n", now.b, now.c, pt);
    if(id) {
      ans[id] = dot(now, p[pt]);
    }
  }
}

#undef int

int main() {
#define int long long
  //puts("CUK");
  int t;
  scanf("%lld", &t);
  while(t--) {
    int q;
    scanf("%lld %lld", &n, &q);
    //puts("GATEL");
    vector<pair<pii, int>> num;
    for(int i = 0; i < n; i++) {
      scanf("%lld %lld", &p[i].b, &p[i].c);
      num.push_back({p[i], 0});
      //printf("done %d\n", i);
    }
    for(int i = 1; i <= q; i++) {
      long long u, v;
      scanf("%lld %lld", &u, &v);
      num.push_back({{u, v}, i});
      //printf("udah %d\n", i);
    }
    //puts("DONE");
    vector<pair<pii, int>> up, down;
    for(auto it : num) {
      if(it.b.b == 0) {
        if(it.b.c >= 0) {
          up.push_back(it);
        } else {
          down.push_back(it);
        }
      } else if(it.b.b > 0) {
        up.push_back(it);
      } else {
        down.push_back(it);
      }
    }
    entry(up);
    entry(down);
    for(int i = 1; i <= q; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}