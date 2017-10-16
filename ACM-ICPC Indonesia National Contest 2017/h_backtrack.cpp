// compile misal jadi ./h
// cara make:
// ./h > h.in

#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int MAX = 200;

int n = 25;
bool vis[N][N];
int sa[MAX], sb[MAX], sc[MAX];

void dfs(int now) {
  if (now == 100) {
    for (int i = 0; i < now; i++) {
      printf("%c%c%c\n", sa[i] + 'A', sb[i] + 'A', sc[i] + 'A');
      fprintf(stderr, "%c%c%c\n", sa[i] + 'A', sb[i] + 'A', sc[i] + 'A');
    }
    cerr << "jancok!" << endl;
    exit(0);
  }
  vector<int> a, b, c;
  for (int i = 0; i < n; i++) {
    a.push_back(i);
    b.push_back(i);
    c.push_back(i);
  }
  random_shuffle(a.begin(), a.end());
  random_shuffle(b.begin(), b.end());
  random_shuffle(c.begin(), c.end());
  for (auto i : a) {
    for (auto j : b) {
      if (vis[i][j]) continue;
      for (auto k : c) {
        if (vis[i][k] || vis[j][k]) continue;
        vis[i][j] = vis[j][i] = 1;
        vis[i][k] = vis[k][i] = 1;
        vis[k][j] = vis[j][k] = 1;
        sa[now] = i;
        sb[now] = j;
        sc[now] = k;
        dfs(now + 1);
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
  return 0;
}
