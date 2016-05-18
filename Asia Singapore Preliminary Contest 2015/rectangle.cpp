#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;
const int N = 1e5 + 5, M = 2e6 + 2, offset = 1e6;

int rm[M<<2], sm[M<<2], lazy[M<<2];

void build(int id = 1, int l = 0, int r = M) {
  rm[id] = sm[id] = 0;
  lazy[id] = 0;
  if(r-l < 2)
    return;
  int mid = (l+r) >> 1, il = id << 1, ir = il|1;
  build(il, l, mid);
  build(ir, mid, r);
}

void upd(int id, int l, int r, int x) {
  lazy[id] += x;
  if(rm[id] == 0)
    sm[id] = r-l;
  rm[id] += x;
  if(!rm[id])
    sm[id] = 0;
}

void shift(int id, int l, int r) {
  int mid = (l+r) >>1, il = id<<1, ir = il | 1;
  upd(il, l, mid, lazy[id]);
  upd(ir, mid, r, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = M) {
  if(x >= r || y <= l) return;
  if(x <= l && y >= r) {
    upd(id, l, r, v);
    return;
  }
  int mid = (l+r)>>1, il = id <<1, ir = il|1;
  shift(id, l, r);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  rm[id] = max(rm[il], rm[ir]);
  if(rm[il] == rm[ir])
    sm[id] = sm[il] + sm[ir];
  else if(rm[il] < rm[ir])
    sm[id] = sm[ir];
  else
    sm[id] = sm[il];
}

int n, x[N][2], y[N][2], s[N];


int main() {
  int c;
  scanf("%d", &c);
  while(c--) {
    scanf("%d", &n);
    vector< pair< int , ii>  > event;
    event.clear();
    build();
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<2; j++) {
        scanf("%d %d", &x[i][j], &y[i][j]);
        event.push_back(make_pair(x[i][j], ii(i, j)));
      }
      scanf("%d", s+i);
    }
    sort(event.begin(), event.end());
    long long ans, sum;
    ans = 0;
    sum = 0;
    int i = 0;
    int last = -1e9;
    while(i<event.size()) {
      int xnow = event[i].first;
      if(ans < rm[1]) {
        ans = rm[1];
        sum = 1LL*(xnow-last)*sm[1];
      }
      else if(ans == rm[1]) {
        sum += 1LL*(xnow-last)*sm[1];
      }
      last = xnow;
      while(i < event.size() && xnow == event[i].first) {
        int v = event[i].second.first;
        if(event[i].second.second)
          update(y[v][0]+offset, y[v][1]+offset, -s[v]);
        else
          update(y[v][0]+offset, y[v][1]+offset, s[v]);
        i++;
      }
    }
    cout << ans << " " << sum << "\n";
  }
  return 0;
} 