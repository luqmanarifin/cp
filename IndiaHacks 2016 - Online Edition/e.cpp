#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

set<int> edge[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].insert(v);
    edge[v].insert(u);
  }
  queue<int> q;
  set<int> lom;
  for(int i = 2; i <= n; i++) {
    lom.insert(i);
  }
  q.push(1);
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    vector<int> rem;
    for(auto it : lom) {
      if(!edge[now].count(it)) {
        rem.push_back(it);
      }
    }
    for(auto it : rem) {
      q.push(it);
      lom.erase(it);
    }
  }
  if(lom.size()) {
    puts("impossible");
    return 0;
  }
  int mn = 0, mk = 0;
  lom.clear();
  for(int i = 2; i <= n; i++) {
    lom.insert(i);
  }
  for(int i = 2; i <= n; i++) {
    if(!edge[1].count(i)) {
      mk++;
      if(lom.count(i)) {
        mn++;
        lom.erase(i);
        q.push(i);
        while(!q.empty()) {
          int now = q.front();
          q.pop();
          vector<int> rem;
          for(auto it : lom) {
            if(!edge[now].count(it)) {
              rem.push_back(it);
            }
          }
          for(auto it : rem) {
            q.push(it);
            lom.erase(it);
          }
        }
      }
    }
  }
  if(mn <= k && k <= mk) {
    puts("possible");
  } else {
    puts("impossible");
  }
  return 0;
}
