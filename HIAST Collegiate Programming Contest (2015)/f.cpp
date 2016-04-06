#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

map<string, vector<string>> edge;
map<string, int> ans;
set<string> done;
string s[105][3];

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    edge.clear();
    ans.clear();
    done.clear();
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        cin >> s[i][j];
      }
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          edge[s[i][j]].push_back(s[i][k]);
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        for(auto it : edge[s[i][j]]) {
          //printf("%s teman %s\n", s[i][j].c_str(), it.c_str());
        }
      }
    }
    done.insert("Ahmad");
    queue<string> q;
    q.push("Ahmad");
    while(!q.empty()) {
      string now = q.front();
      q.pop();
      for(auto it : edge[now]) {
        //printf("%s %s\n", now.c_str(), it.c_str());
        if(!done.count(it)) {
          done.insert(it);
          ans[it] = ans[now] + 1;
          q.push(it);
        }
      }
    }
    set<pair<int, string>> v;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        if(s[i][j] == "Ahmad") {
          v.insert(make_pair(0, s[i][j]));
        } else {
          if(ans[s[i][j]] == 0) {
            ans[s[i][j]] = inf;
          }
          v.insert(make_pair(ans[s[i][j]], s[i][j]));
        }
      }
    }
    printf("%d\n", v.size());
    for(auto it : v) {
      if(it.first == inf) {
        printf("%s undefined\n", it.second.c_str());
      } else {
        printf("%s %d\n", it.second.c_str(), it.first);
      }
    }
  }
  
  return 0;
}