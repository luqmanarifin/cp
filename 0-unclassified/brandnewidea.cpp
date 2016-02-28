#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

vector<vector<char>> s;
vector<int> edge[N];
int to[N], done[N];
char buf[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    
    int p, q;
    scanf("%d %d", &p, &q);
    
    s.assign(p, vector<char>(q));
    for(int i = 0; i < N; i++) edge[i].clear();
    memset(done, 0, sizeof(done));
    
    for(int i = 0; i < p; i++) {
      scanf("%s", buf);
      for(int j = 0; j < q; j++) {
        s[i][j] = buf[j];
      }
    }
    int n = (p + 1) * (q + 1);
    int cnt = 0;
    for(int i = 0; i < p; i++) {
      for(int j = 1; j < q; j++) {
        if(s[i][j] != s[i][j - 1]) {
          int u = i * (q + 1) + j;
          int v = (i + 1) * (q + 1) + j;
          edge[u].push_back(cnt);
          to[cnt++] = v;
          edge[v].push_back(cnt);
          to[cnt++] = u;
        }
      }
    }
    for(int i = 1; i < p; i++) {
      for(int j = 0; j < q; j++) {
        if(s[i][j] != s[i - 1][j]) {
          int u = i * (q + 1) + j;
          int v = i * (q + 1) + j + 1;
          edge[u].push_back(cnt);
          to[cnt++] = v;
          edge[v].push_back(cnt);
          to[cnt++] = u;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int cur = 0;
      for(auto it : edge[i]) {
        if(!done[it]) {
          cur++;
          int e = it;
          while(1) {
            done[e] = done[e ^ 1] = 1;
            int now = to[e], g = -1;
            for(auto jt : edge[now]) {
              if(!done[jt]) {
                g = jt;
                break;
              }
            }
            if(g == -1) break;
            e = g;
          }
        }
      }
      ans += (cur + 1) / 2;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
