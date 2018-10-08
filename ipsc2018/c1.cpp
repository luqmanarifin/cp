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
int mx[200], my[200];
vector<pair<point, point>> cur;
vector<int> px, py;

int add[] = {0, 9, 3, 1};

void dfs(int now) {
  //printf("%d\n", now);
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
  vector<int> ax, ay, cx, cy;
  for (int i = 0; i < now; i++) {
    ax.push_back(a[i].first.x);
    ax.push_back(a[i].second.x);
    ay.push_back(a[i].first.y);
    ay.push_back(a[i].second.y);
  }
  sort(ax.begin(), ax.end());
  sort(ay.begin(), ay.end());
  ax.resize(distance(ax.begin(), unique(ax.begin(), ax.end())));
  ay.resize(distance(ay.begin(), unique(ay.begin(), ay.end())));
  cx.push_back(ax[0] - 2 * add[now]);
  cx.push_back(ax[0] - 1 * add[now]);
  cy.push_back(ay[0] - 2 * add[now]);
  cy.push_back(ay[0] - 1 * add[now]);
  for (auto it : ax) {
    cx.push_back(it);
    cx.push_back(it + add[now]);
    cx.push_back(it + 2 * add[now]);
  }
  for (auto it : ay) {
    cy.push_back(it);
    cy.push_back(it + add[now]);
    cy.push_back(it + 2 * add[now]);
  }
  for (int i = 0; i < cx.size(); i++) {
    for (int j = 0; j < cy.size(); j++) {
      for (int p = i + 1; p < cx.size(); p++) {
        for (int q = j + 1; q < cy.size(); q++) {
          a[now] = make_pair(point(cx[i], cy[j]), point(cx[p], cy[q]));
          dfs(now + 1);
        }
      }
    }
  }
}


int main() {
  for (n = 1; n <= 4; n++) {
    all.clear();
    sz = 0;
    a[0] = make_pair(point(27, 27), point(54, 54));
    dfs(1);
    printf("%d: %d\n", n, sz);
  }

  return 0;
}
