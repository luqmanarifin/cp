#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int pol = 20005;

int p[pol];
int c[pol];

int main() {
  int x, n, m, u;
  scanf("%d %d %d %d", &x, &n, &m, &u);
  int up = inf;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", p + i, c + i);
    if(p[i] <= x) {
      up = min(up, (x - p[i])/u + ((x - p[i])%u? 1 : 0));
    } else {
      up = 0;
    }
  }
  m *= up;
  int need = inf;
  for(int i = 0; i < n; i++) {
    need = min(need, m/c[i] + (m%c[i]? 1 : 0));
  }
  printf("%d\n", need + 1);
  return 0;
}
