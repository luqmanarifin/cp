#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define x first
#define y second

int done[N];
vector<int> edge[N];
vector<int> st[2];

int isduo(int now) {
  return edge[now].size() == 1 && edge[edge[now][0]].size() == 1;
}

int isjomblo(int now) {
  return edge[now].size() == 0;
}

void sudahi(int now) {
  if(done[now] != -1) return;
  done[now] = 1;
  for(auto it : edge[now]) {
    sudahi(it);
  }
}

// white - black - good
pair<pair<int, int>, int> get(int now, int prev, int c) {
  if(done[now] != -1) {
    return {{0, 0}, done[now] == c};
  }
  done[now] = c;
  pair<int, int> ret = {!c, c};
  for(auto it : edge[now]) {
    if(it == prev) continue;
    pair<pair<int, int>, int> dfs = get(it, now, c ^ 1);
    if(!dfs.y) {
      return {{0, 0}, 0};
    }
    ret.x += dfs.x.x;
    ret.y += dfs.x.y;
  }
  return {ret, 1};
}

long long c(int n, int k) {
  long long ret = 1;
  for(int i = 1; i <= k; i++) {
    ret *= n - i + 1;
    ret /= i;
  }
  return ret;
}

int main() {
  memset(done, -1, sizeof(done));

  int n, m;
  scanf("%d %d", &n, &m);
  if(m == 0) {
    printf("3 %I64d", c(n, 3));
    return 0;
  }
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int jomblo = 0, duo = 0;
  int sepi = 1;
  long long ways = 0;
  for(int i = 1; i <= n; i++) {
    if(done[i] != -1) {
      continue;
    }
    if(isjomblo(i)) {
      //cerr << i << " jomblo" << endl;
      jomblo++;
      sudahi(i);
    } else if(isduo(i)) {
      //cerr << i << " duo" << endl;
      duo++;
      sudahi(i);
    } else {
      //puts("jancok");
      sepi = 0;
      pair<pair<int, int>, int> dfs = get(i, -1, 0);
      if(!dfs.y) {
        puts("0 1");
        return 0;
      }
      ways += 1LL * dfs.x.x * (dfs.x.x - 1) / 2;
      ways += 1LL * dfs.x.y * (dfs.x.y - 1) / 2;
    }
  }
  if(sepi) {
    printf("2 %I64d\n", 2LL * duo * (duo - 1) + 1LL * duo * jomblo);
  } else {
    printf("1 %I64d\n", ways);
  }
  return 0;
}
