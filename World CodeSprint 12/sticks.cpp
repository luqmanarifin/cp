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

const int N = 1e6 + 5;
const int SIZE = 105;

bool is[N];
vector<int> p;

long long a[SIZE];
vector<long long> fac[SIZE];
vector<pair<long long, int>> prime[SIZE];

void dfs(int at, int i, long long num) {
  if (i == prime[at].size()) {
    fac[at].push_back(num);
    return;
  }
  for (int j = 0; j <= prime[at][i].second; j++) {
    dfs(at, i + 1, num);
    num *= prime[at][i].first;
  }
}

map<long long, long long> dp;

long long solve(long long n, int at) {
  if (n == 1) return 1;
  if (dp.count(n)) return dp[n];
  long long ans = 1;
  for (auto it : fac[at]) {
    if (it == 1) continue;
    if (n % it == 0) {
      ans = max(ans, it * solve(n / it, at) + 1);
    }
  }
  return dp[n] = ans;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && 1LL * i * p[j] < N; j++) {
      is[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    long long now = a[i];
    for (auto it : p) {
      int cur = 0;
      while (now % it == 0) {
        cur++;
        now /= it;
      }
      if (cur) {
        prime[i].emplace_back(it, cur);
      }
    }
    if (now > 1) {
      prime[i].emplace_back(now, 1);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    dfs(i, 0, 1);
    ans += solve(a[i], i);
  }
  cout << ans << endl;
  return 0;
}
