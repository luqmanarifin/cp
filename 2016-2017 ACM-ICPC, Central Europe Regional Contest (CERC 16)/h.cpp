#include <bits/stdc++.h>

using namespace std;

const int N = 1024, M = 3e5 + 5;

char s[N][N];
int d[N][N];
int n;
int a[M], b[M];
int lo[M], hi[M];
vector<int> que[N];
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
bool valid(int x, int y) {
  return 0 <= min(x, y) && max(x, y) < n;
}

bool add(int i) {
  if (lo[i] >= hi[i]) return false;
  int mid = (lo[i] + hi[i]+1) / 2;
  que[mid].push_back(i);
  return true;
}
int enc(int x, int y) {
  return x * n + y;
}
pair<int, int> dec(int v) {
  return make_pair(v/n, v%n);
}

vector<int> node[N];
int par[N * N];
int find(int x) {
  return par[x] < 0 ? x : par[x] = find(par[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return;
  if (-par[u] > -par[v])
    swap(u, v);
  par[v] += par[u];
  par[u] = v; 
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int xa, xb, ya, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    --xa, --ya, --xb, --yb;
    a[i] = xa * n + ya;
    b[i] = xb * n + yb;
    lo[i] = 0;
    hi[i] = n;
    add(i);
  }
  queue<int > dq;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != '#') {
        d[i][j] = -1;
        continue;
      }
      d[i][j] = 0;
      dq.push(enc(i, j));
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (d[i][j] == 0) continue;
      if (min(i, j) == 0 || max(i, j) == n-1) {
        d[i][j] = 1;
        dq.push(enc(i, j));
      }
    }
  while (!dq.empty()) {
    int v = dq.front(); dq.pop();
    pair<int,int> x = dec(v);
    int dist = d[x.first][x.second];
    for (int i = 0; i < 8; ++i) {
      int xx = x.first + dx[i], yy = x.second + dy[i];
      if (!valid(xx, yy)) continue;
      if (d[xx][yy] != -1) continue;
      d[xx][yy] = dist + 1;
      dq.push(enc(xx, yy));
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      node[d[i][j]].push_back(enc(i,j));
      //~ cerr << d[i][j] << " ";
    }
    //~ cerr << endl;
  }
    
  //~ cerr << " done " << endl;
  bool done = 0;
  while (!done) {
    fill(par, par+n*n, -1);
    //~ cerr << " wow" <<endl;
    done = 1;
    for (int ev = n; ev >= 0; --ev) {
      for (int u : node[ev]) {
        pair<int,int> x = dec(u);
        for (int i = 0; i < 4; ++i) {
          int xx = x.first + dx[i], yy = x.second + dy[i];
          if (!valid(xx, yy)) continue;
          if (d[xx][yy] < ev) continue;
          int v = enc(xx, yy);
          merge(u, v);
        }
      }
      //~ cerr << ev << " evnt " << que[ev].size() << endl;
      for (int id : que[ev]) {
        //~ cerr << ev << " cek " << id << " " << find(a[id]) << " " << find(b[id]) << endl;
        if (find(a[id]) == find(b[id]))
          lo[id] = ev;
        else
          hi[id] = ev-1;
        done &= !add(id); 
        //~ cerr << lo[id] << " " << hi[id] << " " << done << endl;
        //~ cerr << id << " ";
      }
      que[ev].clear();
    }
    
  }
  //~ cerr << " exit" << endl;
  for (int i = 0; i < q; ++i) {
    printf("%d\n", max(lo[i] * 2 - 1, 0));
  }
  return 0;
}
