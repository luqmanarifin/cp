// compile misal jadi ./h
// cara make:
// ./h > h.in

#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int MAX = 200;

int n = 9;
bool vis[N][N];
int sa[MAX], sb[MAX], sc[MAX];
int deg[N];

void dfs(int now) {
  if (now == n * (n - 1) / 6) {
    for (int i = 0; i < now; i++) {
      printf("%c%c%c\n", sa[i] + 'A', sb[i] + 'A', sc[i] + 'A');
      fprintf(stderr, "%c%c%c\n", sa[i] + 'A', sb[i] + 'A', sc[i] + 'A');
    }
    cerr << "jancok!" << endl;
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == n - 1) continue;
    for (int j = i + 1; j < n; j++) {
      //printf("%d %d\n", i, j);
      if (deg[j] == n - 1) continue;
      if (vis[i][j]) continue;
      for (int k = j + 1; k < n; k++) {
        //printf("%d %d %d\n", i, j, k);
        if (deg[k] == n - 1) continue;
        if (vis[i][k] || vis[j][k]) continue;
        //cout << "cok" << endl;
        vis[i][j] = vis[j][i] = 1;
        vis[i][k] = vis[k][i] = 1;
        vis[k][j] = vis[j][k] = 1;
        sa[now] = i;
        sb[now] = j;
        sc[now] = k;
        deg[i] += 2;
        deg[j] += 2;
        deg[k] += 2;
        
        dfs(now + 1);
        
        deg[i] -= 2;
        deg[j] -= 2;
        deg[k] -= 2;
        vis[i][j] = vis[j][i] = 0;
        vis[i][k] = vis[k][i] = 0;
        vis[k][j] = vis[j][k] = 0;
      }
    }
  }
}

int main() {
  srand(time(0));
  for (int i = 0; i < n; i++) vis[i][i] = 1;
  dfs(0);
  puts("ga ada");
  return 0;
}
