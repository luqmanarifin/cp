#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ans[N];

struct point {
  int x, y;
  int id, c;
  point(int x = 0, int y = 0, int id = -1, int c = -1) : x(x), y(y), id(id), c(c) {}
  long long operator%(const point& p) const {
    return 1LL * x * p.y - 1LL * y * p.x;
  }
  long long norm_sq() const {
    return 1LL * x * x + 1LL * y * y;
  }
  bool operator<(const point& p) const {
    long long crs = *this % p;
    if (crs == 0)
      return this->norm_sq() < p.norm_sq();
    return crs > 0;
  }
};

bool isup(point p) {
  if (p.y < 0) return false;
  if (p.y > 0) return true;
  return p.x > 0;
}

int cek(point le, point p, point ri) {
  long long vle = le % p, vri = ri % p;
  if (vle == 0) return -1;
  if (vle < 0) return 1;
  if (vri == 0) return 1;
  if (vri > 0) return -1;
  long long leri = le % ri;
  if (leri > 0) {
    unsigned long long ule = llabs(vle), uri = llabs(vri);
    ule *= ule;
    ule *= (unsigned long long)ri.norm_sq();
    uri *= uri;
    uri *= (unsigned long long)le.norm_sq();
    if (ule < uri)
      return -1;
    if (ule > uri)
      return 1;
    return 0;
  }
  else if (leri < 0) {
    return cek(ri, point(-p.x, -p.y), le);
  }
  else {
    point mid(-le.y, le.x);
    long long crs = mid % p;
    if (crs == 0)
      return 0;
    if (crs > 0)
      return 1;
    else
      return -1;
  }
}

point train[N];
vector<point> after[N];
int nxt[N];
int n, m;
int get(int mid) {
  int last = 0, now = 0, cur = mid;
  for (int i = 0; i < m; i++) {
    last = max((int)after[now].size() - cur, 0);
    now = nxt[now];
    cur = max(train[now].c - last, 0);
  }
  return last;
}

int main() {
  scanf("%d %d", &n, &m);
  vector<point> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y, i, -1));
  }
  for (int j = 0; j < m; j++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    vp.push_back(point(x, y, j, c));
  }
  if (m == 1) {
    int c = vp.back().c;
    printf("%d\n", min(n, c));
    for (int j = 0; j < min(n, c); j++) {
      printf("%d %d\n", j, 0);
    }
    return 0;
  }
  vector<point> up, down;
  for (point p : vp) {
    if (isup(p))
      up.push_back(p);
    else
      down.push_back(p);
  }
  sort(up.begin(), up.end());
  sort(down.begin(), down.end());
  for (int i = 0; i + 1< up.size(); i++)
    assert((up[i] % up[i+1]) >= 0);
  for (int i = 0; i + 1< down.size(); i++)
    assert((down[i] % down[i+1]) >= 0);
  vp = up;
  for (point p : down)
    vp.push_back(p);
  memset(ans, -1, sizeof ans);
  int tot = vp.size();
  int l = tot-1, r = 0;
  while (vp[l].c == -1) l--;
  while (vp[r].c == -1) r++;
  nxt[vp[l].id] = vp[r].id;
  for (int i = 0; i < tot; i++) {
    if (i == r) {
      l = r;
      r++;
      if (r >= tot) r -= tot;
      while (vp[r].c == -1) {
        r++;
        if (r >= tot)
          r -= tot;
      }
      nxt[vp[l].id] = vp[r].id;
      continue;
    }
    int res = cek(vp[l], vp[i], vp[r]);
//    cerr << vp[l].id << " " << vp[i].id << " " << vp[r].id << " " << res << endl;
    if (res == -1) {
//      cerr << vp[l].c << " | " << vp[l].id << endl;
      if (vp[l].c > 0) {
        ans[vp[i].id] = vp[l].id;
        vp[l].c--;
      }
    }
    else if (res == 1) {
      if (vp[r].c > 0) {
        ans[vp[i].id] = vp[r].id;
        vp[r].c--;
      }
    }
    else {
      after[vp[l].id].push_back(vp[i]);
    }
  }
  for (int i = 0; i < tot; i++) if (vp[i].c != -1)
    train[vp[i].id] = vp[i];
  l = 0, r = train[0].c;
  int sisa = get(r);
  while (l < r) {
//    cerr << " bin " << l << " " << r << endl;
    int mid = (l + r) >> 1;
//    cerr << " " << mid << " cmp " << get(mid) << endl;
    if (get(mid) == sisa)
      r = mid;
    else
      l = mid+1;
  }
  int now = 0, cur = l;
  for (int i = 0; i <= m; i++) {
//    cerr << now << " c " << cur << endl;
    train[now].c -= cur;
    while (cur > 0 && !after[now].empty()) {
      cur--;
      ans[after[now].back().id] = now;
  //    cerr << after[now].back().id << " wow " << now << endl;
      after[now].pop_back();
    }
    int nx = nxt[now];
//    cerr << now << " ? " << nx << endl;
    while (train[nx].c > 0 && !after[now].empty()) {
      train[nx].c--;
      ans[after[now].back().id] = nx;
  //    cerr << after[now].back().id << " wow " << nx << endl;
      after[now].pop_back();
    }
    now = nx;
    cur = train[now].c;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += ans[i] != -1;
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) continue;
    printf("%d %d\n", i, ans[i]);
  }
  return 0;
}