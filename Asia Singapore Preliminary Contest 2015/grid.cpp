#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int da[] = {1, -1, 0, 0};
int db[] = {0, 0, 1, -1};

int done[N][N];
int par[N * N];
int k[N * N], l[N * N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

bool valid(int i, int j) {
  return 0 <= i && i < N && 0 <= j && j < N;
}

int dist(int i, int j) {
  return abs(k[i] - k[j]) + abs(l[i] - l[j]);
}

int main() {
  for(int i = 1; i < N * N; i++) {
    par[i] = i;
  }
  
  int n;
  scanf("%d", &n);
  queue<pair<int, int>> q;
  for(int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(done[a][b]) {
      merge(i, done[a][b]);
    } else {
      q.emplace(a, b);
      done[a][b] = i;
    }
    k[i] = a;
    l[i] = b;
  }
  vector<tuple<int, int, int>> edges;
  while(!q.empty()) {
    int a, b;
    tie(a, b) = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int ta = a + da[i];
      int tb = b + db[i];
      if(!valid(ta, tb)) continue;
      if(done[ta][tb]) {
        edges.emplace_back(dist(done[a][b], done[ta][tb]), done[a][b], done[ta][tb]);
      } else {
        done[ta][tb] = done[a][b];
        q.emplace(ta, tb);
      }
    }
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  for(auto it : edges) {
    int cost, a, b;
    tie(cost, a, b) = it;
    if(find(a) != find(b)) {
      ans += cost;
      merge(a, b);
    }
  }
  cout << ans << endl;
  return 0;
}