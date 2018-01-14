#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int inf = 1e9;

#define point pair<int, int> 
#define x first
#define y second

vector<point> build(int* a, int len) {
  vector<point> ret;
  ret.emplace_back(-inf, a[0]);
  for (int i = 1; i < len; i++) {
    if (i % 2 == 0) {
      ret.emplace_back(a[i - 1], a[i]);
    } else {
      ret.emplace_back(a[i], a[i - 1]);
    }
  }
  ret.emplace_back(inf, a[len - 1]);
  return ret;
}

int a[N], b[N];
vector<point> p, q;

void solve_increasing(int n, int m) {
  q = build(a, 2 * n + 1);
  p = build(b, 2 * m + 1);
  //for (auto it : p) printf("%d %d\n", it.first, it.second); printf("\n");
  //for (auto it : q) printf("%d %d\n", it.first, it.second); printf("\n");
  
  vector<tuple<point, int, int>> where;
  int j = 0;
  int st = 1;
  for (int i = 0; i + 1 < p.size(); i++) {
    if (st != i % 2) continue;
    if (st) {
      while (j + 1 < q.size() && q[j + 1].x < p[i].x) j++;
      //printf("can %d %d %d %d\n", p[i].x, p[i].y, q[j].x, q[j].y);
      if (j + 1 < q.size() && p[i].y < q[j].y && q[j].y < p[i + 1].y) {
        where.emplace_back(make_pair(p[i].x, q[j].y), i, j);
        st ^= 1;
      }
    } else {
      while (j + 1 < q.size() && q[j + 1].y < p[i].y) j++;
      if (j + 1 < q.size() && p[i].x < q[j].x && q[j].x < p[i + 1].x) {
        where.emplace_back(make_pair(q[j].x, p[i].y), i, j);
        st ^= 1;
      }
    }
  }
  //for (auto it : where) printf("%d %d\n", get<0>(it).x, get<0>(it).y);
  //assert(where.size() % 2 == 0);
  long long ans = 0;
  for (int i = 0; i + 1 < where.size(); i += 2) {
    point c = get<0>(where[i]);
    point d = get<0>(where[i + 1]);
    ans += 1LL * (d.x - c.x) * (d.y - c.y);
    {
      int l = get<1>(where[i]) + 1;
      int r = get<1>(where[i + 1]);
      assert((r - l) % 2 == 0);
      for (int j = l; j <= r; j += 2) {
        int dx = p[j+1].x - p[j].x;
        int dy = d.y - p[j].y;
        ans -= 1LL * dx * dy;
      }
    }
    {
      int l = get<2>(where[i]) + 1;
      int r = get<2>(where[i + 1]);
      assert((r - l) % 2 == 0);
      for (int j = l + 1; j <= r; j += 2) {
        int dx = q[j+1].x - q[j].x;
        int dy = q[j].y - c.y;
        ans -= 1LL * dx * dy;
      }
    }
  }
  printf("%d %lld\n", where.size() / 2, ans);
}

void solve_decreasing(int n, int m) {
  p = build(a, 2 * n + 1);
  q = build(b, 2 * m + 1);

  //for (auto it : p) printf("%d %d\n", it.first, it.second); printf("\n");
  //for (auto it : q) printf("%d %d\n", it.first, it.second); printf("\n");
  
  vector<tuple<point, int, int>> where;
  int j = 0;
  int st = 1;
  for (int i = 0; i + 1 < p.size(); i++) {
    if (st != i % 2) continue;
    if (st) {
      while (j + 1 < q.size() && q[j + 1].x < p[i].x) j++;
      if (j + 1 < q.size() && p[i].y > q[j].y && q[j].y > p[i + 1].y) {
        where.emplace_back(make_pair(p[i].x, q[j].y), i, j);
        st ^= 1;
      }
    } else {
      while (j + 1 < q.size() && q[j + 1].y > p[i].y) j++;
      if (j + 1 < q.size() && p[i].x < q[j].x && q[j].x < p[i + 1].x) {
        where.emplace_back(make_pair(q[j].x, p[i].y), i, j);
        st ^= 1;
      }
    }
  }
  //for (auto it : where) printf("%d %d\n", get<0>(it).x, get<0>(it).y);
  //assert(where.size() % 2 == 0);
  long long ans = 0;
  for (int i = 0; i + 1 < where.size(); i += 2) {
    point c = get<0>(where[i]);
    point d = get<0>(where[i + 1]);
    ans += 1LL * abs(d.x - c.x) * abs(d.y - c.y);
    {
      int l = get<1>(where[i]) + 1;
      int r = get<1>(where[i + 1]);
      assert((r - l) % 2 == 0);
      for (int j = l; j <= r; j += 2) {
        int dx = abs(p[j+1].x - p[j].x);
        int dy = abs(d.y - p[j].y);
        ans -= 1LL * dx * dy;
      }
    }
    {
      int l = get<2>(where[i]) + 1;
      int r = get<2>(where[i + 1]);
      assert((r - l) % 2 == 0);
      for (int j = l + 1; j <= r; j += 2) {
        int dx = abs(q[j+1].x - q[j].x);
        int dy = abs(q[j].y - c.y);
        ans -= 1LL * dx * dy;
      }
    }
  }
  printf("%d %lld\n", where.size() / 2, ans);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 2 * n + 1; i++) scanf("%d", a + i);
  for (int i = 0; i < 2 * m + 1; i++) scanf("%d", b + i);
  if (a[0] < a[2]) {
    solve_increasing(n, m);
  } else {
    solve_decreasing(n, m);
  }
  return 0;
}
