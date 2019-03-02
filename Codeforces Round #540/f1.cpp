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

const int N = 3e5 + 5;

int c[N][3];
int tot[3], a[N];
vector<int> edge[N];
int ans;

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    for (int i = 0; i < 3; i++) {
      c[now][i] += c[it][i];
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    tot[a[i]]++;
    c[i][a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 2; i <= n; i++) {
    bool ok = 1;
    if (c[i][1] > 0 && c[i][2] > 0) {
      ok = 0;
    }
    if (tot[1] - c[i][1] > 0 && tot[2] - c[i][2] > 0) {
      ok = 0;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}
