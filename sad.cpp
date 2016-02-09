#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int inf = 1e9;

int dist[N][N];
int a[N];
int maxi, n;
vector<int> edge[N];
bool ada[N];

long long code() {
  long long ret = 0;
  for(int i = 0; i < n; i++) {
    ret = ret * 16 + a[i];
  }
  return ret;
}

void relax(long long val) {
  for(int i = n - 1; i >= 0; i--) {
    a[i] = val % 16;
    val /= 16;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    set<long long> done;
    maxi = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int num, val;
      scanf("%d %d", &num, &val);
      num--;
      val--;
      a[num] = val;
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = inf;
      }
      dist[i][i] = 0;
    }
    
    int m;
    scanf("%d", &m);
    while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      edge[u].push_back(v);
      edge[v].push_back(u);
      dist[u][v] = dist[v][u] = 1;
      maxi = max(maxi, u);
      maxi = max(maxi, v);
    }
    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    queue<pair<long long, int>> q;
    q.emplace(code(), 0);
    done.insert(code());
    while(!q.empty()) {
      long long now;
      int cost;
      tie(now, cost) = q.front();
      q.pop();
      relax(now);
      for(int i = 0; i < maxi; i++) {
        ada[i] = 0;
      }
      bool nice = 1;
      for(int i = 0; i < n; i++) {
        ada[a[i]] = 1;
        if(a[i] != i) {
          nice = 0;
        }
        //printf("%d ", a[i]);
      }
      //printf("\n");
      if(nice) {
        printf("%d\n", cost);
        break;
      }
      for(int i = 0; i < n; i++) {
        for(auto it : edge[a[i]]) {
          if(!ada[it] && dist[i][it] <= dist[i][a[i]]) {
            int temp = a[i];
            a[i] = it;
            long long near = code();
            if(!done.count(near)) {
              q.emplace(near, cost + 1);
              done.insert(near);
            }
            a[i] = temp;
          }
        }
      }
    }
  }
  
  return 0;
}
