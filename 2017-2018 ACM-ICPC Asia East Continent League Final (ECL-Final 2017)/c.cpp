#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const double eps = 1e-10;

inline bool le(double x, double y) { return x < y + eps; }
inline bool lt(double x, double y) { return x + eps < y; }

int a[N], b[N];
int n;

void add(vector<pair<double, double > > & vb, pair<double, double> p, pair<double, double> q) {
  if (vb.empty()) {
    vb.push_back(p);
    vb.push_back(q);
    return;
  }
  int cur = 0;
  vector<pair<double, double> > res;
  for (int i = 0; i < vb.size(); ++i) {
    if (lt(vb[i].first, p.first)) {
      res.push_back(vb[i]);
    }
    else {
      if (i > 0 && lt(vb[i-1].first, p.first) && lt(p.first, vb[i].first)) {
        double grad = (vb[i].second - vb[i-1].second) / (vb[i].first - vb[i-1].first); 
        res.push_back(make_pair(p.first, p.second + vb[i-1].second + grad * (p.first - vb[i-1].first)));
      }
      if (i > 0 && lt(vb[i-1].first, q.first) && lt(q.first, vb[i].first)) {
        double grad = (vb[i].second - vb[i-1].second) / (vb[i].first - vb[i-1].first); 
        res.push_back(make_pair(q.first, q.second + vb[i-1].second + grad * (q.first - vb[i-1].first)));
      }
      if (le(vb[i].first, q.first)) {
        double grad = (q.second - p.second) / (q.first - p.first); 
        res.push_back(make_pair(vb[i].first, vb[i].second + p.second + grad * (vb[i].first - p.first)));
      }
      else {
        res.push_back(vb[i]);
      }
    }
  }
  if (lt(vb.back().first, q.first))
    res.push_back(q);
  vb.swap(res);
}

bool can(double ma, int ab) {
  vector<pair<double, double> > res;
  add(res, make_pair(0, b[0]), make_pair(b[0], 0));
  double lastx = 0;
  for (int i = 1; i < n; ++i) {
    double x = res.back().first;
    for (int j = 0; j + 1 < res.size(); ++j) {
      if (lt(res[j].first, lastx)) continue;
      if (lt(ma, res[j+1].second + b[i])) continue;
      if (lt(res[j].second + b[i], ma)) {
        x = res[j].first;
        break;
      }
      double dy = res[j].second + b[i] - ma;
      double dxdy = (res[j+1].first - res[j].first) / (res[j+1].second - res[j].second);
      x = max(res[j].first, res[j].first + fabs(dxdy) * dy + eps);
      x = min(x, res[j+1].first);
      break;
    }
    lastx = x;
    add(res, make_pair(x, b[i]), make_pair(x + b[i], 0));
  }
  //~ cerr << ma << endl;
  //~ for (int i = 0; i < res.size(); ++i) {
    //~ cerr << res[i].first << " " << res[i].second << endl;
  //~ }
  if (res.empty()) return true;
  for (int i = 0; i < res.size(); ++i) {
    //~ cerr << ma << " "<< res[i].second << " " << lt(ma, res[i].second) << endl;
    if (lt(ma, res[i].second)) return false;
  }
  if (le(res.back().first, ab)) return true;  
  pair<double, double> p = res[0], q = res[1];
  //~ cerr << ab + q.first - p.first << " " << res.back().first << endl;
  if (lt(ab + q.first - p.first, res.back().first)) return false;
  //~ cerr << " done " << endl;
  p.first += ab;
  q.first += ab;
  add(res, p, q);
  for (int i = 0; i < res.size(); ++i) {
    //~ cerr << res[i].first << " " << res[i].second << " cek " << lt(ma, res[i].second) << endl;
    if (lt(ma, res[i].second))
      return false;
  }
  return true;
}


int main() {
  int t;
  scanf("%d", &t);
  for (int tc=1 ; tc <= t; ++tc) {
    scanf("%d", &n);
    long long tot = 0;
    for (int i= 0; i <= n; ++i) {
      int s;
      scanf("%d", &s);
      tot += s;
    }
    int ab = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", a+i, b+i);
      ab =a[i] + b[i];
    }
    sort(b, b+n);
    reverse(b, b+n);
    double le = 0, ri = 0;
    for (int i = 0; i < n; ++i) ri += b[i];
    for (int it = 0; it < 70; ++it) {
      //~ cerr << le << " binser " << ri << endl;
      double mid = (le + ri) * 0.5;
      bool res = can(mid, ab);
      //~ cerr << " result " << res << endl;
      if (res)
        ri = mid;
      else
        le = mid;
    }
    //~ cerr << le << " " << ri << endl;
    double ans = tot + (le + ri) * 0.5;
    printf("Case #%d: %.20lf\n", tc, ans);
  }
  return 0;
}
