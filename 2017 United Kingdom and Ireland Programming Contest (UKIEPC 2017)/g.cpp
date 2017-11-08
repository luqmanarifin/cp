#include <bits/stdc++.h>

using namespace std;

struct point {
  point() {}
  point(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator==(const point& other) {
    return x == other.x && y == other.y && z == other.z;
  }
  bool operator!=(const point& other) {
    return !(*this == other);
  }
  bool operator<(const point& other) const {
    if (x != other.x) return x < other.x;
    if (y != other.y) return y < other.y;
    return z < other.z;
  }
  int x, y, z;
};

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int dist(point a, point b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int main() {
  point sa, fa;
  point sb, fb;
  scanf("%d %d %d %d %d %d", &sa.x, &sa.y, &sa.z, &fa.x, &fa.y, &fa.z);
  scanf("%d %d %d %d %d %d", &sb.x, &sb.y, &sb.z, &fb.x, &fb.y, &fb.z);
  vector<point> ans;
  while (sa != fa) {
    ans.push_back(sa);
    for (int i = 0; i < 6; i++) {
      point ta = point(sa.x + dx[i], sa.y + dy[i], sa.z + dz[i]);
      if (dist(ta, fa) < dist(sa, fa)) {
        sa = ta;
        break;
      }
    }
  }
  ans.push_back(fa);
  
  vector<point> tmp;
  srand(time(0));
  while (sb != fb) {
    tmp.push_back(sb);
    //printf("%d %d %d\n", sb.x, sb.y, sb.z);
    vector<pair<int, point> > pos;
    bool found = 0;
    for (int i = 0; i < 6; i++) {
      point tb = point(sb.x + dx[i], sb.y + dy[i], sb.z + dz[i]);
      if (tmp.size() < ans.size()) {
        if (ans[tmp.size()] == tb) continue;
        if (ans[tmp.size() - 1] == tb) continue;
      } else {
        if (ans.back() == tb) continue;
      }
      pos.emplace_back(dist(tb, fb), tb);
    }
    sort(pos.begin(), pos.end());
    int v = 1;
    while (v < pos.size() && pos[v].first == pos[v-1].first) v++;
    sb = pos[rand() % v].second;
  }
  tmp.push_back(fb);
  
  for (int i = 0; i < max(ans.size(), tmp.size()); i++) {
    point a = (i < ans.size()? ans[i] : ans.back());
    point b = (i < tmp.size()? tmp[i] : tmp.back());
    printf("(%d %d %d) (%d %d %d)\n", a.x, a.y, a.z, b.x, b.y, b.z);
  }
  return 0;
}
