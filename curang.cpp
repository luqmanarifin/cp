#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string str = "ACGT";
vector<int> d[N];
int a[N], par[N], ans[N];

// relation part
int comp[N];          // for ancestor only
vector<int> who[N];   // who on which ID

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      ans[i] = comp[i] = -1;
      who[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int cnt = 0;
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
    for(int i = 0; i < n; i++) {
      if(a[i] > 0 && i) {
        ans[i] = ans[a[i] - 1];
      } else {
        ans[i] = cnt++;
      }
      if(cnt > 4) {
        puts("Impossible");
        goto cuk;
      }
    }
    for(int i = 0; i < n; i++) {
      cout << ans[i] << endl;
      printf("%c", str[ans[i]]);
    }
    printf("\n");
    cuk:;
  }
  
  return 0;
}
