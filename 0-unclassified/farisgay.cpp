#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int cok[105][105];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(n > 10) {
    puts("YES");
    return 0;
  }
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    cok[u][v] = cok[v][u] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      for(int k = j + 1; k <= n; k++) {
        if(cok[i][j] == cok[j][k] && cok[i][k] == cok[j][k]) {
          puts("YES");
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}