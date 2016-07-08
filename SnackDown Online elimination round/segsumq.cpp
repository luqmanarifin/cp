#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e6 + 6;
int n, q, a[N], b[N];
vector< pair<int, int> > x[N<<2];
vector< pair<long long, long long> > sum[N<<2];
bool cmp(pair<int, int> c, pair<int, int> d) {
  return c.second == 0 || 1LL * c.second * d.first < 1LL * c.first * d.second;
}
 
void build(int id = 1, int l = 0, int r = n) {
  if(r-l < 2) {
    x[id].push_back(make_pair(a[l], b[l]));
    sum[id].push_back(make_pair(a[l], b[l]));
    return;
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
  int c = 0, d = 0;
  long long suma = 0, sumb = 0;
  while(c < x[il].size() && d < x[ir].size()) {
    pair< int, int> chosed;
    if(cmp(x[il][c], x[ir][d]))
      chosed = x[il][c++];
    else
      chosed = x[ir][d++];
    x[id].push_back(chosed);
    suma += chosed.first;
    sumb += chosed.second;
    sum[id].push_back(make_pair(suma, sumb));
  
  }
  while(c < x[il].size()) {
    pair< int, int> chosed = x[il][c++];
    x[id].push_back(chosed);
    suma += chosed.first;
    sumb += chosed.second;
    sum[id].push_back(make_pair(suma, sumb));
  }
  while(d < x[ir].size()) {
    pair< int, int> chosed = x[ir][d++];
    x[id].push_back(chosed);
    suma += chosed.first;
    sumb += chosed.second;
    sum[id].push_back(make_pair(suma, sumb));
  }
  // cerr << id << endl;
  // for(int i = 0; i<x[id].size(); i++)
  //   cerr << x[id][i].first << " " << x[id][i].second << endl;
}
 
long long get(int xx, int y, long long c, long long d, int id = 1, int l = 0, int r = n) {
  if(l >= y || r <= xx)
    return 0;
  if(xx <= l && r <= y) {
    int ll = -1, rr = (int)x[id].size() -1 ;
    while(ll < rr) {
      int mid = (ll + rr + 1)>>1;
      if(x[id][mid].first * c >= x[id][mid].second * d)
        ll = mid;
      else
        rr = mid-1;
    }
    if(ll < 0)
      return 0;
    return max(0LL, c * sum[id][ll].first - d * sum[id][ll].second);
  }
  int mid = (l + r) >> 1, il = id<<1, ir = il|1;
  return get(xx, y, c, d, il, l, mid) + get(xx, y, c, d, ir, mid, r);
}
 
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int j = 0; j<n; j++)
    scanf("%d", b+j);
  build();
  scanf("%d", &q);
  while(q--) {
    int l, r, c, d;
    scanf("%d%d%d%d", &l, &r, &c, &d);
    printf("%lld\n", get(l-1, r, c, d));
    fflush(stdout);
  }
  return 0;
}  