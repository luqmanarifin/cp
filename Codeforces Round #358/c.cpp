#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], cnt[N];
long long big[N];
vector<pair<int, int>> edge[N];

void dfs(int now, long long cur, int bef) {
  big[now] = cur;
  cnt[now] = 1;
  for(auto it : edge[now]) {
    int to = it.first;
    int c = it.second;
    if(to == bef) continue;
    dfs(to, max(1LL * c, cur + c), now);
    cnt[now] += cnt[to]; 
  }
}

int dfs(int now, int bef) {
  //printf("%d\n", now);
  int ret = 0;
  for(auto it : edge[now]) {
    int to = it.first;
    if(to == bef) continue;
    ret += dfs(to, now);
  }
  if(big[now] > a[now]) {
    return cnt[now];
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", a + i);
  for(int i = 2; i <= n; i++) {
    int p, c;
    scanf("%d %d", &p, &c);
    edge[p].emplace_back(i, c);
    edge[i].emplace_back(p, c);
  }
  dfs(1, 0, -1);
  cout << dfs(1, -1) << endl;
  return 0;
}
