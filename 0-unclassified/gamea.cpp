#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

bool done[205];
vector<int> pre[205];
vector<int> aft[205];
vector<int> here[4];

int n;
int loc[205];
int got[205];
bool vis[205];

int solve(int now) {
  memset(done, 0, sizeof(done));
  int udah = 0;
  int time = 0;
  while(udah < n) {
    for(auto id : here[now]) {
      if(done[id]) continue;
      bool valid = 1;
      for(auto p : pre[id]) {
        if(!done[p]) {
          valid = 0;
          break;
        }
      }
      if(valid) {
        udah++;
        time++;
        done[id] = 1;
      }
    }
    if(udah < n) {
      now++, time++;
    }
    if(now == 4) now = 1;
  }
  return time;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", loc + i);
    here[loc[i]].push_back(i);
  }
  queue<int> topo;
  vector<int> ret;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &got[i]);
    if(got[i] == 0) {
      topo.push(i);
      ret.push_back(i);
    }
    for(int j = 0; j < got[i]; j++) {
      int a;
      scanf("%d", &a);
      pre[i].push_back(a);
      aft[a].push_back(i);
    }
  }
  
  while(!topo.empty()) {
    int now = topo.front();
    topo.pop();
    for(auto next : aft[now]) {
      got[next]--;
      if(got[next] == 0) {
        topo.push(next);
        ret.push_back(next);
      }
    }
  }
  for(int i = 1; i <= 3; i++) {
    memset(vis, 0, sizeof(vis));
    for(auto it : here[i]) {
      vis[it] = 1;
    }
    here[i].clear();
    for(auto it : ret) {
      if(vis[it]) {
        here[i].push_back(it);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    for(auto it : pre[i]) {
      vis[it] = 1;
    }
    pre[i].clear();
    for(auto it : ret) {
      if(vis[it]) {
        pre[i].push_back(it);
      }
    }
  }
  int ans = inf;
  for(int i = 1; i <= 3; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;
  return 0;
}