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

const int N = 4005;
const long long mod = 1e9 + 7;

int n;
pair<int, int> ans[N][N];

pair<int, int> join(int a, int b, int c, int d) {
  if (b < a) {
    if (c <= b) {
      if (d + 1 < a) {
        return {a, d};
      } else {
        return {0, n - 1};
      }
    } else {
      if (b + 1 < c) {
        return {c, b};
      } else {
        return {0, n - 1};
      }
    }
  } else {
    pair<int, int> l = {a, b};
    pair<int, int> r = {c, d};
    auto lef = min(l, r);
    auto rig = max(l, r);
    a = lef.first;
    b = lef.second;
    c = rig.first;
    d = rig.second;
    // mengandung
    if (a <= c && c <= b && a <= d && d <= b) return {a, b};
    // through
    if (c <= b) return {a, d};
    // terpisah
    if (a == 0 && d == n - 1) {
      if (b + 1 == c) return {0, n - 1};
      return {c, b};
    } else {
      return {a, d};
    }
  }
}

vector<pair<int, int>> solve(vector<pair<int, int>> a) {
  pair<int, int> ans[a.size()][a.size()];
  for (int i = 0; i < a.size(); i++) {
    auto now = a[i];
    ans[i][i] = now;
    for (int j = i + 1; j < a.size(); j++) {
      now = join(now.first, now.second, a[j].first, a[j].second);
      ans[i][j] = now;
    }
  }
  vector<pair<int, int>> ret;
  for (int len = 0; len < a.size(); len++) {
    for (int i = 0; i + len < a.size(); i++) {
      ret.push_back(ans[i][i + len]);
    }
  }
  return ret;
}

int a[N];
int dp[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) p.emplace_back(i, i);
  p = solve(p);
  //for (auto it : a) printf("%d %d\n", it.first, it.second); printf("\n");
  p = solve(p);
  //for (auto it : a) printf("%d %d\n", it.first, it.second); printf("\n");
  for (auto it : p) dp[it.first][it.second]++;
  long long pipin = 0;
  for (int i = 0; i < n; i++) {
    int now = a[i];
    for (int j = i; j < n; j++) {
      now = max(now, a[j]);
      pipin += 1LL * dp[i][j] * now;
      pipin %= mod;
    }
    for (int j = 0; j < i - 1; j++) {
      now = max(now, a[j]);
      pipin += 1LL * dp[i][j] * now;
      pipin %= mod;
    }
  }
  cout << pipin << endl;
  return 0;
}
