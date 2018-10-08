#include <bits/stdc++.h>

using namespace std;

const int N = 4;

struct point {
  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}
  bool operator==(const point& p) const {
    return x == p.x && y == p.y;
  }
  bool operator<(const point& p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  int x, y;
};  

set<vector<pair<point, point>>> all;
int sz = 0;
pair<point, point> a[N];
int n;
int mx[2 * N], my[2 * N];
vector<pair<point, point>> cur;
vector<int> px, py;

void dfs(int now) {
  if (now == n) {
    px.clear();
    py.clear();
    for (int i = 0; i < n; i++) {
      px.push_back(a[i].first.x);
      px.push_back(a[i].second.x);
      py.push_back(a[i].first.y);
      py.push_back(a[i].second.y);
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    px.resize(distance(px.begin(), unique(px.begin(), px.end())));
    py.resize(distance(py.begin(), unique(py.begin(), py.end())));
    for (int i = 0; i < px.size(); i++) mx[px[i]] = i;
    for (int i = 0; i < py.size(); i++) my[py[i]] = i;
    cur.clear();
    for (int i = 0; i < n; i++) {
      pair<point, point> po = make_pair(point(mx[a[i].first.x], my[a[i].first.y]), point(mx[a[i].second.x], my[a[i].second.y]));
      cur.push_back(po);
    }
    sort(cur.begin(), cur.end());
    for (int i = 1; i < n; i++) {
      if (cur[i] == cur[i - 1]) {
        return;
      }
    }
    if (!all.count(cur)) {
      sz++;
      all.insert(cur);
    }
    return;
  }
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      for (int p = i + 1; p < 2 * n; p++) {
        for (int q = j + 1; q < 2 * n; q++) {
          a[now] = make_pair(point(i, j), point(p, q));
          dfs(now + 1);
        }
      }
    }
  }
}


int main() {
  for (n = 4; n <= 4; n++) {
    all.clear();
    sz = 0;
    dfs(0);
    printf("%d: %d\n", n, sz);
  }

  return 0;
}
