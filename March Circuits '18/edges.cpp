#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int rmq[N][20];
int pos[N];
int cnt, a[N];
int lef[N], rig[N];

void dfs(int now, int bef = -1) {
  rmq[cnt][0] = a[now];
  pos[now] = cnt;
  lef[now] = rig[now] = cnt; 
  cnt++;
  //printf("%d ", now);
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
  } 
  rig[now] = cnt - 1;
}

int find(int l, int r) {
  if (l > r) return 0;
  int g = __builtin_clz(r - l + 1) ^ 31;
  return rmq[l][g] | rmq[r-(1<<g)+1][g];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  } 
  dfs(1); //printf("\n");
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      rmq[i][j] = (rmq[i][j-1] | rmq[i+(1<<(j-1))][j-1]);
    }
  }
  int ans = 0;
  //for (int i = 1; i <= n; i++) printf("%d lala %d %d\n", i, lef[i], rig[i]);
  for (int i = 2; i <= n; i++) {
    int now = i;
    int sub = find(lef[now], rig[now]);
    int l = find(0, lef[now]-1);
    int r = find(rig[now]+1, n-1);
    int els = (l | r);
    //printf("%d: %d %d %d\n", i, sub, l, r);
    if (sub == els) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
