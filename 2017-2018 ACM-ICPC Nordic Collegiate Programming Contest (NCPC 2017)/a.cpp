#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long double inf = 1e18;

long long pos[N];
int pa[N << 2], pb[N << 2];
double la[N << 2], lb[N << 2];
pair<long long, int > vp[N];
int a, b, t, rr, m, pre[N << 2];
long long len;
void build(int id = 1, int l = 0, int r = m) {
  la[id] = lb[id] = inf;
  pa[id] = pb[id] = -1;
  if (r-l < 2) {
    la[id] = lb[id] = (double)pos[l]/a;
    pa[id] = pb[id] = 0;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void push(int id, int l, int r) {
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (pa[id] != -1) {
    if (la[il] > la[id]) {
  //    cerr << l << " " << la[id] << endl;
      pa[il] = pa[id];
      la[il] = la[id];
    }
    double nla = la[id] + (double)(pos[mid] - pos[l])/a;
    if (la[ir] > nla) {
  //    cerr << mid << " " << nla << endl;
      pa[ir] = pa[id];
      la[ir] = nla;
    }
    la[id] = inf;
    pa[id] = -1;
  }
  if (pb[id] != -1) {
    if (lb[il] > lb[id]) {
      pb[il] = pb[id];
      lb[il] = lb[id];
    }
    double nlb = lb[id] + (double)(pos[mid] - pos[l])/b;
    if (lb[ir] > nlb) {
      pb[ir] = pb[id];
      lb[ir] = nlb;
    }
    lb[id] = inf;
    pb[id] = -1;
  }
}

void update_a(int x, int y, double val, int p, int id = 1, int l = 0, int r = m) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    double nla = val + (double)(pos[l] - pos[x])/a;
//    cerr << " upd_a " << x << " " << y << " " << la[id] << " " << nla << endl;
    if (la[id] > nla) {
      pa[id] = p;
      la[id] = nla;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update_a(x, y, val, p, il, l, mid);
  update_a(x, y, val, p, ir, mid, r);
}


void update_b(int x, int y, double val, int p, int id = 1, int l = 0, int r = m) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    double nlb = val + (double)(pos[l] - pos[x])/b;
    if (lb[id] > nlb) {
      pb[id] = p;
      lb[id] = nlb;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update_b(x, y, val, p, il, l, mid);
  update_b(x, y, val, p, ir, mid, r);
}

double get(int x, int id = 1, int l = 0, int r = m) {
  if (r-l < 2) {
    if (la[id] < lb[id])
      pre[x] = pa[id];
    else
      pre[x] = pb[id];
//    cerr << " res " << x << " " << la[id] << " " << lb[id] << " " << pa[id] << " " << pb[id] << endl;
    return min(la[id], lb[id]);
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  if (x < mid)
    return get(x, il, l, mid);
  else
    return get(x, ir, mid, r);
}

int main() {
  scanf("%lld %d %d %d %d", &len, &a, &b, &t, &rr);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &vp[i].first);
    vp[i].second = i;
  }
  sort(vp, vp+n);
  m = n + 2;
  pos[0] = 0;
  pos[m-1] = len;
  for (int i = 0; i < n; i++)
    pos[i+1] = vp[i].first;
  build();
  for (int i = 1; i <= n; i++) {
    long long st = pos[i] + 1LL * t * a;
    long long en = st + 1LL * rr * b;
    double cur = get(i) + t;
    int le, ri;
    le = lower_bound(pos+i+1, pos+m, st) - pos;
    ri = upper_bound(pos+i+1, pos+m, en) - pos;
    if (le < ri) {
      double nx = cur + (double)(pos[le]-st)/b;
      update_b(le, ri, nx, i);
    }
    if (ri < m) {
      double full = cur + rr + (double)(pos[ri]-en)/a;
      update_a(ri, m, full, i);
    }
  }
  get(m-1);
  vector<int> ans;
  int now = pre[m-1];
  while (now > 0) {
    ans.push_back(vp[now-1].second);
    now = pre[now];
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d%c", ans[i], " \n"[(i+1) == ans.size()]);
  }
  return 0;
}