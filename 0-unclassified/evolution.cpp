#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string str = "ACGT";
vector<int> d[N];
int a[N], par[N], ans[N];

// relation part
int comp[N];          // for ancestor only
vector<int> enemy[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for(int i = 1; i < N; i++) {
    for(int j = i + i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      ans[i] = comp[i] = -1;
      enemy[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    vector<pair<int, int>> law;
    for(int i = 0; i < n; i++) {
      if(a[i] > n - i) {
        puts("Impossible");
        goto cuk;
      }
    }
    if(a[0] != n) {
      puts("Impossible");
      goto cuk;
    }
    for(int i = 1; i < n; i++) {
      int pol = 0;
      for(auto it : d[i]) {
        pol = max(pol, it + a[it]);
      }
      for(int j = max(i, pol); j < i + a[i]; j++) {
        merge(j - i, j);
      }
      if(i + a[i] < n) {
        if(find(a[i]) == find(i + a[i])) {
          puts("Impossible");
          goto cuk;
        }
        law.emplace_back(a[i], i + a[i]);
      }
    }
    for(auto it : law) {
      int u = find(it.first);
      int v = find(it.second);
      if(u == v) {
        puts("Impossible");
        goto cuk;
      }
      enemy[u].push_back(v);
      enemy[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
      if(comp[find(i)] != -1) {
        ans[i] = comp[find(i)];
        continue;
      }
      bool found = 0;
      for(int c = 0; c < 4; c++) {
        bool musuh = 0;
        for(auto it : enemy[find(i)]) {
          if(comp[it] == c) {
            musuh = 1;
            break;
          }
        }
        if(!musuh) {
          found = 1;
          comp[find(i)] = c;
          ans[i] = c;
          break;
        }
      }
      FOUND:;
      if(!found) {
        puts("Impossible");
        goto cuk;
      }
    }
    /*
    for(int i = 0; i < n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
    */
    for(int i = 0; i < n; i++) {
      printf("%c", str[ans[i]]);
    }
    printf("\n");
    cuk:;
  }
  
  return 0;
}
