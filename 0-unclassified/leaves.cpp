#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

int n, cnt;
vector<int> edge[N];
set<pair<int, int>> s[N];
int h[N];

int height = 0;

void insert(set<pair<int, int>>& a, set<pair<int, int>>& b) {
  for(auto it : b) {
    int len = it.second - it.first, g = it.first;
    auto p = a.lower_bound(make_pair(g, -1));
    if(p != a.begin()) p--;
    while(len) {
      //printf("len %d\n", len);
      while(p != a.end() && p->second < g) p++;
      if(p == a.end()) {
        a.insert(make_pair(g, g + len));
        break;
      }
      if(g < p->first) {
        if(g + len >= p->first) {
          int del = min(len, p->first - g);
          pair<int, int> to = {g, p->second};
          a.erase(p);
          p = a.insert(to).first;
          g = p->second;
          len -= del;
        } else {
          p = a.insert(make_pair(g, g + len)).first;
          g = p->second;
          len = 0;
        }
      } else {
        //puts("TAEK");
        int from = p->first;
        g = p->second;
        auto toErase = p;
        p++;
        
        int to;
        if(p == a.end()) {
          to = g + len;
          len = 0;
        } else {
          if(g + len >= p->first) {
            to = p->second;
            int del = min(len, p->first - g);
            len -= del;
            a.erase(p);
          } else {
            to = g + len;
            len = 0;
          }
        }
        a.erase(toErase);
        p = a.insert(make_pair(from, to)).first;
        g = to;
      }
    }
  }
}

int dfs(int now, int bef) {
  int p = cnt++;
  bool leaf = 1;
  //printf("now %d\n", now);
  h[now] = h[bef] + 1;
  height = max(height, h[now]);
  for(auto it : edge[now]) {  
    if(it == bef) continue;
    leaf = 0;
    int near = dfs(it, now);
    if(s[p].size() < s[near].size()) {
      insert(s[near], s[p]);
      p = near;
    } else {
      insert(s[p], s[near]);
    }
  }
  if(leaf) s[p].insert(make_pair(0, 1));
  vector<pair<int, int>> tmp;
  for(auto it : s[p]) tmp.emplace_back(it.first + 1, it.second + 1);
  s[p].clear();
  //printf("%d : ", now);
  for(auto it : tmp) {
    s[p].insert(it);
    //printf("%d %d\n", it.first, it.second);
  }
  return p;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ans = 0;
  for(auto it : edge[1]) {
    int p = dfs(it, 1);
    ans = max(ans, s[p].rbegin()->second - 1);
  }
  cout << ans << endl;
  return 0;
}