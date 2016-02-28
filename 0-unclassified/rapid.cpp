#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9;

vector<int> edge[N];
int a[N];
int dist[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    while(n--) {
      int m;
      scanf("%d", &m);
      for(int i = 0; i < m; i++) {
        scanf("%d", a + i);
      }
      for(int i = 1; i < m; i++) {
        edge[a[i]].push_back(a[i - 1]);
        edge[a[i - 1]].push_back(a[i]);
      }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      for(int i = 0; i < N; i++) {
        dist[i] = inf;
      }
      dist[u] = 0;
      queue<int> st;
      st.push(u);
      while(!st.empty()) {
        int now = st.front();
        st.pop();
        for(int i = 0; i < edge[now].size(); i++) {
          if(dist[edge[now][i]] == inf) {
            dist[edge[now][i]] = dist[now] + 1;
            st.push(edge[now][i]);
          }
        }
      }
      if(dist[v] == inf) puts("-1");
      else {
        printf("%d\n", dist[v]);
      }
    }
  }
  
  return 0;
}
