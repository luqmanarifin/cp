#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 10;

int c[55][55];
bool done[55][55];
int n;

bool bisa(int now) {
  for(int i = 1; i <= n; i++) {
    if(i == now) continue;
    if(!done[now][i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &c[i][j]);
    }
  }
  int best = -inf, from, to;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) continue;
      int comp = -inf, sec;
      for(int k = 1; k <= n; k++) {
        if(j == k) continue;
        if(c[j][k] > comp) {
          comp = c[j][k];
          sec = k;
        }
      }
      if(comp == -inf) comp = 0;
      if(c[i][j] - comp > best) {
        best = c[i][j] - comp;
        from = i, to = j;
      }
    }
  }
  printf("%d %d\n", from, to);
  fflush(stdout);
  
  int a, b;
  scanf("%d %d", &a, &b);
  done[from][to] = 1;
  done[a][b] = 1;
  int now = b;
  while(bisa(b)) {
    best = -inf, to;
    for(int i = 1; i <= n; i++) {
      if(done[now][i] || i == now) {
        continue;
      }
      int comp = -inf;
      for(int j = 1; j <= n; j++) {
        if(done[i][j] || i == j) {
          continue;
        }
        comp = max(comp, c[i][j]);
      }
      if(comp == -inf) comp = 0;
      if(c[now][i] - comp > best) {
        best = c[now][i] - comp;
        to = i;
      }
    }
    done[now][to] = 1;
    printf("%d %d\n", now, to);
    fflush(stdout);
    
    if(~scanf("%d %d", &a, &b)) {
      done[a][b] = 1;
      now = b;
    } else {
      break;
    }
  }
  
  return 0;
}
