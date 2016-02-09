#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool is[N];
vector<int> edge[N];
vector<int> p[N];
int rem[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(is[i]) {
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    for(int j = 2; j < N; j++) {
      if(num % j == 0) {
        while(num % j == 0) {
          num /= j;
          p[i][j]++;
        }
      }
    }
  }
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int ans = 0;
  for(int prime = 2; prime < N; prime++) {
    if(is[prime]) {
      continue;
    }
    stack<int> topo;
    for(int i = 0; i < n; i++) {
      rem[i] = edge[i].size();
      if(rem[i] == 1) topo.push(i);
    }
    while(!topo.empty()) {
      int now = topo.top();
      topo.pop();
      for(auto it : edge[now]) {
        int del = min(p[now][prime], p[it][prime]);
        ans += del;
        p[now][prime] -= del;
        p[it][prime] -= del;
        rem[it]--;
        if(rem[it] == 1) {
          topo.push(it);
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(auto it : edge[i]) {
        int del = min(p[i][prime], p[it][prime]);
        ans += del;
        p[i][prime] -= del;
        p[it][prime] -= del;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
