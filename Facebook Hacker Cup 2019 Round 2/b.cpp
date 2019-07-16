#include <bits/stdc++.h>

using namespace std;

const int N = 4005;

int par[N];
int st[2][N]; // 0 as middle, 1 as pinggir kiri

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u])); 
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

bool done[N];
vector<int> el[N];
int mp[N];  // mapping from root to index of component

bitset<N * N * 2 + 5> ada;
int track[N * N * 2 + 5];
int ans[N];
int str[N];

int f(int pos, int val) {
  val += 4000;
  return pos * 8001 + val;
}

void dfs(int pos, int val) {
  if (pos == 0) return;
  int at = f(pos, val);
  if (track[at] == 1) {
    ans[pos] = 1;
    dfs(pos - 1, val - el[pos].size());
  } else {
    ans[pos] = 0;
    dfs(pos - 1, val + el[pos].size());
  } 
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    ada.reset();
    memset(done, 0, sizeof(done));
    for (int i = 0; i < N; i++) {
      par[i] = i;
      st[0][i] = N;
      st[1][i] = N;
      el[i].clear();
    }

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      int mid = (x + y) / 2;
      if ((x + y) % 2 == 0) {
        st[0][mid] = min(st[0][mid], x);
      } else {
        st[1][mid] = min(st[1][mid], x);
      }
    }
    for (int mid = 1; mid <= n; mid++) {
      for (int i = mid; i >= st[0][mid]; i--) {
        merge(i, mid + (mid - i));
      }
      for (int i = mid; i >= st[1][mid]; i--) {
        merge(i, mid + 1 + (mid - i));
      }
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
      int root = find(i);
      if (!done[root]) {
        num++;
        done[root] = 1;
        mp[root] = num;
        el[num].push_back(i);
      } else {
        el[mp[root]].push_back(i);
      }
    }
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    ada[f(0, 0)] = 1;
    while (!q.empty()) {
      int pos, val;
      tie(pos, val) = q.front();
      q.pop();
      if (pos >= num) continue;
      int size = el[pos + 1].size();
      {
        int to_val = val + size;
        int at = f(pos + 1, to_val);
        if (!ada[at]) {
          ada[at] = 1;
          track[at] = 1;
          q.emplace(pos + 1, to_val);
        }
      }
      {
        int to_val = val - size;
        int at = f(pos + 1, to_val);
        if (!ada[at]) {
          ada[at] = 1;
          track[at] = 0;
          q.emplace(pos + 1, to_val);
        }
      }
    }
    for (int dif = 0; dif <= n; dif++) {
      {
        int at = f(num, dif);
        if (ada[at]) {
          dfs(num, dif);
          break;
        }
      }
      {
        int at = f(num, -dif);
        if (ada[at]) {
          dfs(num, -dif);
          break;
        }
      }
    }
    for (int i = 1; i <= num; i++) {
      for (auto it : el[i]) {
        str[it] = ans[i];
      }
    }
    printf("Case #%d: ", tt);
    for (int i = 1; i <= n; i++) {
      printf("%d", str[i]);
    }
    printf("\n");
  }

  return 0;
}