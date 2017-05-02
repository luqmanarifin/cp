#include <bits/stdc++.h>

using namespace std;

const int N = 16;

int vis[1 << N];
int a[1 << N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(vis, 0, sizeof(vis));
    
    int n, k;
    scanf("%d %d %s", &n, &k, s);
    int now = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') {
        now |= (1 << i);
      } 
    }
    int p = 0;
    memset(vis, -1, sizeof(vis));
    while (vis[now] == -1) {
      //printf("%d: %d\n", p+1, now);
      vis[now] = p;
      a[p++] = now;
      
      if (now % 2) {
        now ^= (1<<(n-1));
      }
      int last = now % 2;
      now -= last;
      last ^= 1;
      now >>= 1;
      now |= last << (n-1);
    }
    int offset = vis[now];
    int cycle = p - offset;
    printf("Experiment #%d:\n", tt);
    while (k--) {
      int v;
      scanf("%d", &v);
      int ans;
      if (v <= offset) {
        ans = offset;
      } else {
        ans = (v - offset) % cycle + offset;
      }
      for (int i = 0; i < n; i++) {
        if (a[ans] & (1 << i)) {
          printf("+");
        } else {
          printf("-");
        }
      }
      printf("\n");
    }
  }

  return 0;
}
