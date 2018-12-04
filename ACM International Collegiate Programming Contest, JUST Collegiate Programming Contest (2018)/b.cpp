#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1e4 + 5;
const int BIG = 1e6 + 5;

char c[N];
int a[N];
int last[BIG];

bool done[N];
vector<int> edge[N];
vector<int> ada[BIG];
int ans;

int dfs(int now) {
  if (done[now]) return 0;
  done[now] = 1;
  bool ada = 0;
  for (auto it : edge[now]) {
    ada |= dfs(it);
  }
  if (ada) ans--;
  return !ada;
}

int main() {
  for (int i = 2; i < BIG; i++) {
    if (last[i] == 0) {
      for (int j = i; j < BIG; j += i) {
        last[j] = i;
      }
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));
    for (int i = 0; i < BIG; i++) ada[i].clear();
    for (int i = 0; i < N; i++) edge[i].clear();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      while (a[i] > 1) {
        int c = last[a[i]];
        ada[c].push_back(i);
        while (a[i] % c == 0) a[i] /= c;
      }
    }
    for (int i = 0; i < n; i++) {
      scanf(" %c", c + i);
    }
    for (int i = 2; i < BIG; i++) {
      if (ada[i].size() > 1) {
        assert(ada[i].size() == 2);
        int u = ada[i][0];
        int v = ada[i][1];
        if (c[u] == c[v]) continue;
        edge[u].push_back(v);
        edge[v].push_back(u);
      }
    }
    ans = n;
    for (int i = 0; i < n; i++) dfs(i);
    printf("%d\n", ans);
  }

  return 0;
}
