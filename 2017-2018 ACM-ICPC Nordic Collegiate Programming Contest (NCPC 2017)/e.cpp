#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N], d[N][N];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i]+j);
    }
  }
  int x, y;
  scanf("%d %d", &x, &y);
  x--; y--;
  set<pair<int, pair<int, int> > > st;
  d[x][y] = min(0, a[x][y]);
  st.insert(make_pair(d[x][y], make_pair(x, y)));
  while (!st.empty()) {
    auto it = st.begin();
    x = it->second.first, y = it->second.second;
    st.erase(it);
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      int nv = max(a[xx][yy], d[x][y]);
      if (nv < d[xx][yy]) {
        st.erase(make_pair(d[xx][yy], make_pair(xx, yy)));
        d[xx][yy] = nv;
        st.insert(make_pair(d[xx][yy], make_pair(xx, yy)));
      }
    }
  }
  long long tot = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      tot -= d[i][j];
/*  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cerr << d[i][j] << " ";
    cerr << endl;
  } */
  cout << tot << endl;
  return 0;
}