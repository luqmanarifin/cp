#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e18;

long long power(long long a, long long b, long long mod) {
  if (b == 0) return 1 % mod;
  long long tmp = power(a, b / 2, mod);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a, long long mod) {
  return power(a, mod - 2, mod);
}

vector<int> all[N];
int at[N], comp[N];

long long dist(int u, int v) {
  if (comp[u] != comp[v]) return inf;
  int d = at[v] - at[u];
  if (d < 0) d += all[comp[u]].size();
  return d;
}

int main() {
  long long a, b, p, x;
  scanf("%lld %lld %lld %lld", &a, &b, &p, &x);
  
  set<int> done;
  for (int i = 1; i < p; i++) {
    long long now = i;
    while (!done.count(now)) {
      done.insert(now);
      comp[now] = i;
      at[now] = all[i].size();
      all[i].push_back(now);
      now = (now * a) % p;
    }
  }
  
  long long ans = 0;
  for (int i = 1; i <= min(p - 1, x); i++) {
    long long rig = b * inv(i, p) % p;
    long long ada = 1 + (x - i) / p;
    long long s = power(a, i, p);
    long long d = dist(s, rig);
    //printf("mod %d: %lld %lld %lld %lld\n", i, rig, ada, s, d);
    if (d < ada) {
      ans += 1 + (ada - 1 - d) / all[comp[s]].size();
    }
  }
  cout << ans << endl;
  return 0;
}
