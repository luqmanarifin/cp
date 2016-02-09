#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int big = 1e5 + 5;

int done[N][N][2];
vector<int> edge[N][2];
int a[big], b[big];
// edge color
vector<pair<int, int>> ans[N];

// syarat :
// pasti punya temen yang from
// harus udah aman dari 'to'
void dfs(int now, int s, int from, int to) {
  int f = done[now][from][s];
  assert(f);
  done[now][from][s] = 0;
  done[f][from][s ^ 1] = 0;
  if(done[f][to][s ^ 1]) {
    dfs(f, s ^ 1, to, from);
  }
  done[now][to][s] = f;
  done[f][to][s ^ 1] = now;
}

int main() {
  int na, nb, m;
  scanf("%d %d %d", &na, &nb, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", a + i, b + i);
    edge[a[i]][0].push_back(b[i]);
    edge[b[i]][1].push_back(a[i]);
  }
  int col = 0;
  for(int i = 1; i <= na; i++) {
    col = max(col, (int)edge[i][0].size());
  }
  for(int i = 1; i <= nb; i++) {
    col = max(col, (int)edge[i][1].size());
  }
  printf("%d\n", col);
  for(int it = 0; it < m; it++) {
    int all = -1, l = -1, r = -1;
    for(int i = 1; i <= col; i++) {
      if(!done[a[it]][i][0] && !done[b[it]][i][1]) {
        all = i;
        break;
      }
      if(!done[a[it]][i][0] && done[b[it]][i][1]) {
        r = i;
      }
      if(done[a[it]][i][0] && !done[b[it]][i][1]) {
        l = i;
      }
    }
    if(all != -1) {
      done[a[it]][all][0] = b[it];
      done[b[it]][all][1] = a[it];
      continue;
    }
    dfs(b[it], 1, r, l);
    done[a[it]][r][0] = b[it];
    done[b[it]][r][1] = a[it];
  }
  for(int i = 1; i <= na; i++) {
    for(int j = 1; j <= col; j++) {
      if(done[i][j][0]) {
        ans[i].emplace_back(done[i][j][0], j);
      }
    }
    sort(ans[i].begin(), ans[i].end());
  }
  for(int i = 0; i < m; i++) {
    int at = lower_bound(ans[a[i]].begin(), ans[a[i]].end(), make_pair(b[i], -1)) - ans[a[i]].begin();
    printf("%d ", ans[a[i]][at].second);
  }
  return 0;
}
