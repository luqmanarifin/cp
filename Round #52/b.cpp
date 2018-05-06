
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int cnt[N];

vector<int> rem;

void pre(int now, int bef) {
  for (auto it : edge[now]) if (it.first != bef) {
    pre(it.first, now);
    cnt[now] += cnt[it.first];
  }
  cnt[now]++;
}

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (it.first == bef) continue;
    if (it.second) {
      rem.push_back(cnt[it.first]);
      continue;
    }
    dfs(it.first, now);
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }  
  pre(1, 0);
  dfs(1, 0);
  sort(rem.begin(), rem.end());
  reverse(rem.begin(), rem.end());
  int now = n, ans = 0;
  for (auto it : rem) {
    if (now <= k) break;
    //printf("rem %d\n", it);
    ans++;
    now -= it;
  }
  if (now <= k) {
    cout << ans << endl;
  } else {
    puts("-1");
  }
  return 0;
}
