#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<string> all; 
map<string, int> id;

string a[N], b[N];
vector<int> edge[N];
int par[N];
int to[N], l[N], r[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = par[find(v)];
}

int main() {
  int n;
  cin >> n;
  while(n) {
    all.clear();
    id.clear();
    for(int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      all.insert(a[i]);
      all.insert(b[i]);
    }
    int node = 0;
    for(auto it : all) {
      id[it] = node;
      par[node] = node;
      to[node] = 0;
      l[node] = r[node] = 0;
      edge[node].clear();
      node++;
    }
    for(int i = 0; i < n; i++) {
      int ida = id[a[i]];
      int idb = id[b[i]];
      edge[ida].push_back(idb);
      merge(ida, idb);
      to[idb]++;
      l[idb]++;
      r[ida]++;
    }
    priority_queue<int> pq;
    vector<int> topo;
    for(int i = 0; i < n; i++) {
      if(a[i] > b[i]) {
        puts("!BST");
        goto NEXT;
      }
    }
    for(int i = 1; i < node; i++) {
      if(find(i) != find(i - 1)) {
        puts("!BST");
        goto NEXT;
      }
    }
    for(int i = 0; i < node; i++) {
      if(to[i] == 0) {
        pq.push(-i);
      }
    }
    while(!pq.empty()) {
      int now = pq.top();
      now = -now;
      pq.pop();
      topo.push_back(now);
      for(auto it : edge[now]) {
        to[it]--;
        if(to[it] == 0) {
          pq.push(-it);
        }
      }
    }
    for(int i = 0; i < topo.size(); i++) {
      if(i != topo[i]) {
        puts("!BST");
        goto NEXT;
      }
    }
    for(int i = 0; i < node; i++) {
      if(edge[i].size() > 3 || l[i] > 2 || r[i] > 2) {
        puts("!BST");
        goto NEXT;
      }
    }
    for(int i = 0; i < node; i++) {
      if(l[i] == 2 || r[i] == 2) {
        puts("BST?");
        goto NEXT;
      }
    }
    puts("BST!");
    NEXT:;
    scanf("%d", &n);
  }
  
  return 0;
}
