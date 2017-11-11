#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int BIG = 32000;

bool is[BIG], rem[N];
vector<int> p;
vector<int> factors;
int a[N];

vector<pair<int, int>> prime;

void dfs(int i, int now) {
  if (i == prime.size()) {
    factors.push_back(now);
    return;
  }
  for (int j = 0; j <= prime[i].second; j++) {
    dfs(i + 1, now);
    now *= prime[i].first;
  }
}

void entry(int v) {
  prime.clear();
  for (auto it : p) {
    int cnt = 0;
    while (v % it == 0) {
      cnt++;
      v /= it;
    }
    if (cnt) {
      prime.emplace_back(it, cnt);
    }
  }
  if (v > 1) {
    prime.emplace_back(v, 1);
  }
  dfs(0, 1);
}

int main() {
  for (int i = 2; i < BIG; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < BIG; j += i) {
        is[j] = 1;
      }
    }
  }
  int ada = 0;
  for (auto it : p) {
    if (it * it <= 100) ada++;
  }
  cout << ada << endl;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    entry(abs(a[i]));
  }
  factors.push_back(1);
  
  sort(factors.begin(), factors.end());
  factors.resize(distance(factors.begin(), unique(factors.begin(), factors.end())));
  reverse(factors.begin(), factors.end());
  for (auto it : factors) {
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (rem[i]) continue;
      if (a[i] % it == 0) {
        cur += a[i];
      }
    }
    if (cur < 0) {
      for (int i = 0; i < n; i++) {
        if (a[i] % it == 0) {
          rem[i] = 1;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) if (!rem[i]) ans += a[i];
  cout << ans << endl;
  return 0;
}
