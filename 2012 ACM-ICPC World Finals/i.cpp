#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int x[N], y[N];
char mirror[N];
// arah = 0: atas, 1: kanan, 2:bawah, 3:kiri
int change(int d, char c) {
  if (c == '/') {
    if (d == 0 || d == 3)
      return 3-d;
    return 3-d;
  }
  else { // '\'
    if (d == 0 || d == 1)
      return 1 - d;
    return 2 + 3 - d;
  }
}
set<pair<int, int> > row[N], col[N];
set<pair<int, int> > contain;

int next(int x, int y, int dir) {
  if (dir == 0) { // atas
    auto it = col[y].lower_bound(make_pair(x, -1));
    if (it == col[y].begin()) return -1;
    return (--it)->second;
  }
  else if (dir == 1) { // kanan
    auto it = row[x].upper_bound(make_pair(y, N));
    if (it == row[x].end()) return -1;
    return it->second;
  }
  else if (dir == 2) { // bawah
    auto it = col[y].upper_bound(make_pair(x, N));
    if (it == col[y].end()) return -1;
    return it->second;
  }
  else { // kiri
    auto it = row[x].lower_bound(make_pair(x, -1));
    if (it == row[x].begin()) return -1;
    return (--it)->second;
  }
}

vector<tuple<int, int, int, int, int> > seg1;
vector<tuple<int, int, int, int, int> > seg2;

int main() {
  int r, c, n, m;
  while (scanf("%d %d %d %d", &r, &c, &n, &m) == 4) {
    for (int i = 0; i <= r; ++i)
      row[i].clear();
    for (int i = 0; i <= c; ++i)
      col[i].clear();
    contain.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", x+i, y+i);
      mirror[i] = '/';
      row[x[i]].insert(make_pair(y[i], i));
      contain.insert(make_pair(x[i], y[i]));
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", x+n+i, y+n+i);
      mirror[i+n] = '\\';
      row[y[i+n]].insert(make_pair(x[i+n], i+n));
      contain.insert(make_pair(x[i+n], y[i+n]));
    }
    x[n+m] = r;
    y[n+m] = c+1;
    row[r].insert(make_pair(c+1, n+m));
    int xx = 1, yy = 0, dir = 1;
    int now = next(xx, yy, dir);
    seg1.clear(); seg2.clear();
    while (now != n + m || now != -1) {
      seg1.emplace_back(xx, yy, x[now], y[now], dir);
      dir = change(dir, mirror[now]);
      xx = x[now], yy = y[now];
      now = next(xx, yy, dir);
    }
    if (now == n+m) {
      puts("0");
      continue;
    }
    else {
      if (dir == 0)
        seg1.emplace_back(xx, yy, 0, yy, dir);
      else if (dir == 1)
        seg1.emplace_back(xx, yy, xx, c+1, dir);
      else if (dir == 2)
        seg1.emplace_back(xx, yy, r+1, yy, dir);
      else
        seg1.emplace_back(xx, yy, xx, 0, dir);
    }
    xx = r, yy = c+1, dir = 3;
    while (now != -1) {
      seg2.emplace_back(xx, yy, x[now], y[now], dir);
      dir = change(dir, mirror[now]);
      xx = x[now], yy = y[now];
      now = next(xx, yy, dir);
    }
    if (dir == 0)
      seg2.emplace_back(xx, yy, 0, yy, dir);
    else if (dir == 1)
      seg2.emplace_back(xx, yy, xx, c+1, dir);
    else if (dir == 2)
      seg2.emplace_back(xx, yy, r+1, yy, dir);
    else
      seg2.emplace_back(xx, yy, xx, 0, dir);
    {
      vector<pair<int, int> > event;
      vector<tuple<int, int, int> > que;
      for (int i = 0; i < ; ++i) {
        
      }
    }
    {
      for (int i = 0; i < n; ++i) {
        
      }
    }
  }
  return 0;
}
