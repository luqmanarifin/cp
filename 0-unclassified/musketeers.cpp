#include <bits/stdc++.h>

using namespace std;

const int N = 4005;
const int inf = 1e9;

char s[N][N];
vector<int> edge[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
    s[a][b] = s[b][a] = 1;
  }
  int ans = inf;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(!s[i][j]) {
        continue;
      }
      if(edge[i].size() < edge[j].size()) {
        for(auto it : edge[i]) {
          if(s[it][j]) {
            ans = min(ans, (int)edge[i].size() + (int)edge[j].size() + (int)edge[it].size() - 6);
          }
        }
      } else {
        for(auto it : edge[j]) {
          if(s[it][i]) {
            ans = min(ans, (int)edge[i].size() + (int)edge[j].size() + (int)edge[it].size() - 6);
          }
        }
      }
    }
  }
  if(ans == inf) {
    puts("-1");
  } else {
    cout << ans << endl;
  }
  return 0;
}
