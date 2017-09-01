#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int offset = 1e5;

struct item {
  item(int x, int y, int id) : x(x), y(y), id(id) {}
  int x, y, id;
};

int g[N], p[N], t[N];
int ansx[N], ansy[N];

vector<item> in[N], out[N];

bool cmp(item l, item r) {
  if (l.x != r.x) return l.x < r.x;
  return l.y > r.y;
}

int main() {
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", g + i, p + i, t + i);
    if (g[i] == 1) {
      in[p[i] + offset - t[i]].push_back(item(p[i], 0, i));
      out[p[i] + offset - t[i]].push_back(item(p[i], h, i));
    } else {
      in[p[i] + offset - t[i]].push_back(item(0, p[i], i));
      out[p[i] + offset - t[i]].push_back(item(w, p[i], i));
    }
  }
  for (int i = 0; i < N; i++) {
    sort(in[i].begin(), in[i].end(), cmp);
    sort(out[i].begin(), out[i].end(), cmp);
    for (int j = 0; j < in[i].size(); j++) {
      ansx[in[i][j].id] = out[i][j].x;
      ansy[in[i][j].id] = out[i][j].y;
    }
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", ansx[i], ansy[i]);
  return 0;
}