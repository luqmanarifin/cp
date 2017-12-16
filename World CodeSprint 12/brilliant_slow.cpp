/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> dp[N], all;
vector<int> edge[N];
int a[N];

int id(int u) {
  return lower_bound(all.begin(), all.end(), u) - all.begin();
}

void dfs(int now, int bef) {
  int leaf = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    leaf = 0;
    dfs(it, now);
  }
  if (leaf) {
    for (int i = 0; i < all.size(); i++) {
      if (i <= a[now]) {
        dp[now][i] = 0;
      } else {
        dp[now][i] = 1;
      }
    }
    return;
  }
  for (int i = 0; i < all.size(); i++) {
    dp[now][i] = (i != a[now]);
    for (auto it : edge[now]) {
      if (it == bef) continue;
      dp[now][i] += dp[it][i];
    }
  }
  for (int i = (int) all.size() - 2; i >= 0; i--) {
    dp[now][i] = min(dp[now][i], dp[now][i + 1]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    all.push_back(a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 1; i <= n; i++) a[i] = id(a[i]);
  for (int i = 1; i <= n; i++) dp[i].assign(all.size(), N);
  dfs(1, 0);
  int ans = N;
  for (int i = 0; i < all.size(); i++) ans = min(ans, dp[1][i]);
  cout << ans << endl;
  return 0;
}
