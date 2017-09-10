// Author: Luka Kalinovcic
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

#define MAX 100

typedef long long int64;

struct Point {
  Point (int64 r, int64 c) : r(r), c(c) {}
  int64 r;
  int64 c;
};

bool operator<(Point const& a, Point const& b) {
  return a.r != b.r ? a.r < b.r : a.c < b.c;
}

int R, C;
char pattern[MAX][MAX + 1];
set<Point> seen[MAX][MAX];
Point exit(0, 0);
enum PatternType { NONE, VECTOR, TILES } pattern_type = NONE;
Point vec(0, 0);

int const dr[4] = {-1, 0, 1, 0};
int const dc[4] = {0, 1, 0, -1};

int mod(int64 a, int n) {
  int t = a % n;
  return t < 0 ? t + n : t;
}

void Input() {
  scanf("%d%d", &R, &C);
  for (int r = 0; r < R; ++r) {
    scanf("%s", pattern[r]);
    for (int c = 0; c < C; ++c) {
      if (pattern[r][c] != '#' && pattern[r][c] != '.') {
        exit = Point(r, c);
        pattern[r][c] = '.';
      }
    }
  }
}

void Explore() {
  queue<Point> Q;
  seen[exit.r][exit.c].insert(exit);
  Q.push(exit);
  while (!Q.empty() && (int)seen[exit.r][exit.c].size() < R + C) {
    Point s = Q.front();
    Q.pop();
    for (int d = 0; d < 4; ++d) {
      Point t(s.r + dr[d], s.c + dc[d]);
      int rr = mod(t.r, R);
      int cc = mod(t.c, C);
      if (pattern[rr][cc] == '#') continue;
      if (seen[rr][cc].count(t)) continue;
      seen[rr][cc].insert(t);
      Q.push(t);
    }
  }
}

void Analyze() {
  if (seen[exit.r][exit.c].size() > 1) {
    set<Point> deltas;

    set<Point> const& S = seen[exit.r][exit.c];
    set<Point>::iterator it = S.begin();
    set<Point>::iterator jt = S.begin();
    for (++jt; jt != S.end(); ++it, ++jt) {
      deltas.insert(Point(jt->r - it->r, jt->c - it->c));
    }
    if (deltas.size() == 1) {
      pattern_type = VECTOR;
      vec = *deltas.begin();
    } else {
      pattern_type = TILES;
    }
  } else {
    pattern_type = NONE;
  }
}

bool Solve(Point const& p) {
  int rr = mod(p.r, R);
  int cc = mod(p.c, C);
  if (pattern_type == NONE) {
    return seen[rr][cc].count(p);
  } else if (pattern_type == TILES) {
    return !seen[rr][cc].empty();
  } else {
    int64 lo = -1000000000;
    int64 hi = 1000000000;
    while (hi - lo > 10) {
      int64 mid1 = (2 * lo + hi) / 3;
      int64 mid2 = (lo + 2 * hi) / 3;
      Point t1 = Point(p.r + vec.r * mid1, p.c + vec.c * mid1);
      Point t2 = Point(p.r + vec.r * mid2, p.c + vec.c * mid2);
      int64 dist1 = abs(exit.r - t1.r) + abs(exit.c - t1.c);
      int64 dist2 = abs(exit.r - t2.r) + abs(exit.c - t2.c);
      if (dist1 < dist2) hi = mid2;
      else lo = mid1;
    }
    for (int k = lo; k <= hi; ++k) {
      Point t = Point(p.r + vec.r * k, p.c + vec.c * k);
      if (seen[rr][cc].count(t)) return true;
    }
    return false;
  }
}

int main() {
  Input();
  Explore();
  Analyze();

  int Q;
  scanf("%d", &Q);
  for (int q = 0; q < Q; ++q) {
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%s\n", Solve(Point(r, c)) ? "yes" : "no");
  }

  return 0;
}
