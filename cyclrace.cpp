#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

#define getp(a) get<0>(a)
#define geta(a) get<1>(a)
#define getb(a) get<2>(a)

int m, ask[N];
long long a[N], b[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<pair<long long, long long>> p, g;
  while(q--) {
    int t, time, at, sp;
    scanf("%d %d", &t, &time);
    if(t == 1) {
      scanf("%d %d", &at, &sp);
      b[at] -= 1LL * (sp - a[at]) * time;
      a[at] = sp;
      p.emplace_back(a[at], b[at]);
    } else {
      ask[m++] = time;
    }
  }
  sort(p.begin(), p.end());
  for(int i = 0; i < p.size(); i++) {
    if(!g.empty() && g.back().first == p[i].first) {
      g.pop_back();
    }
    g.push_back(p[i]);
  }
  
  vector<tuple<double, long long, long long>> c;
  c.emplace_back(0., 0, 0);
  for(auto it : g) {
    long long u, v;
    tie(u, v) = it;
    while((double)(getb(c.back()) - v)/(u - geta(c.back())) < getp(c.back())) {
      c.pop_back();
    }
    double val = (double)(getb(c.back()) - v)/(u - geta(c.back()));
    c.emplace_back(val, u, v);
  }
  int j = 0;
  for(int i = 0; i < m; i++) {
    while(j + 1 < c.size() && getp(c[j + 1]) < ask[i]) j++;
    printf("%lld\n", ask[i] * geta(c[j]) + getb(c[j]));
  }
  return 0;
}
