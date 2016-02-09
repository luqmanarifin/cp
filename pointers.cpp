#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 15;
#define MAXN 2*N*N

string str = "^><v";
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int n, m;
int source, sink, flow;
char s[N][N];
int cap[MAXN][MAXN], c[MAXN][MAXN];
int dist[MAXN], p[MAXN];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void augment(int x, int minflow) {
  if(x == source) {
    flow = minflow;
    return;
  }
  if(p[x] == -1) {
    flow = 0;
    return;
  }
  augment(p[x], min(minflow, cap[p[x]][x]));
  cap[p[x]][x] -= flow;
  cap[x][p[x]] += flow;
}

int code(int i, int j) {
  return i * m + j;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(cap, 0, sizeof(cap));
    memset(c, 0, sizeof(c));
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    
    source = 2 * n * m;
    sink = source + 1;
    int size = sink + 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int k = 0; k < 4; k++) {
          int ti = i + dx[k];
          int tj = j + dy[k];
          if(valid(ti, tj)) {
            int cf = code(i, j);
            int ct = code(ti, tj) + n*m;
            cap[cf][ct] = 1;
            c[cf][ct] = (s[i][j] != str[k]);
            c[ct][cf] = -(s[i][j] != str[k]);
          }
        }
        cap[source][code(i, j)] = 1;
        cap[code(i, j) + n*m][sink] = 1;
      }
    }
    
    int mf = 0, mincost = 0;
    while(1) {
      flow = 0;
      for(int i = 0; i < size; i++) {
        dist[i] = inf;
        p[i] = -1;
      }
      set<pair<int, int>> pq;
      pq.insert(make_pair(0, source));
      dist[source] = 0;
      while(!pq.empty()) {
        int cost = (pq.begin())->first;
        int now = (pq.begin())->second;
        auto it = pq.begin();
        pq.erase(it);
        if(dist[now] != cost) continue;
        for(int i = 0; i < size; i++) {
          if(cap[now][i] > 0) {
            int ncos = cost + c[now][i];
            if(ncos < dist[i]) {
              pq.erase(make_pair(dist[i], i));
              dist[i] = ncos;
              p[i] = now;
              pq.insert(make_pair(dist[i], i));
            }
          }
        }
      }
      augment(sink, inf);
      if(flow == 0) break;
      mf += flow;
      mincost += dist[sink];
    }
    printf("Case #%d: ", tt);
    if(mf == n * m) {
      printf("%d\n", mincost);
    } else {
      puts("-1");
    }
  }
  
  return 0;
}
