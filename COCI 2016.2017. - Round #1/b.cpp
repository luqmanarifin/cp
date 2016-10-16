#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int inf = 1e9;

char s[15][N];
int vis[15][N];
int n = 10, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '.' && vis[i][j] == inf;
}

int main() {
  scanf("%d", &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, inf);
  queue<pair<int, int>> q;
  q.emplace(n - 1, 0);
  while (!q.empty()) {
    int a, b;
    tie(a, b) = q.front();
    //printf("bfs %d %d\n", a, b);
    q.pop();
    if (valid(a - 1, b + 1)) {
      vis[a - 1][b + 1] = 1;
      q.emplace(a - 1, b + 1);
    }
    if (valid(a + 1, b + 1)) {
      vis[a + 1][b + 1] = -1;
      q.emplace(a + 1, b + 1);
    }
    if (a == n - 1 || a == 0) {
      if (valid(a, b + 1)) {
        vis[a][b + 1] = 0;
        q.emplace(a, b + 1);
      }
    }
  }
  //puts("bfs done");
  vector<int> p;
  for (int i = 0; i < n; i++) {
    if (vis[i][m - 1] != inf) {
      int h = i;
      int j = m - 1;
      while (j > 0) {
        //printf("%d %d\n", h, j);
        p.push_back(h);
        h += vis[h][j];
        j--;
      }
      //printf("%d %d\n", h, j);
      p.push_back(h);
      reverse(p.begin(), p.end());
      break;
    }
  }
  assert(p.size() == m);
  vector<pair<int, int>> ans;
  //for (auto it : p) printf("%d ", it); printf("\n");
  for (int i = 0; i < p.size(); i++) {
    if (i + 1 < p.size() && p[i] > p[i + 1]) {
      int j = i;
      while (j + 1 < p.size() && (p[j] > p[j + 1] || (p[j] == p[j + 1 && p[j] == 0]))) j++;
      ans.emplace_back(i, j - i);
      i = j;
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d %d\n", it.first, it.second);
  return 0;
}
