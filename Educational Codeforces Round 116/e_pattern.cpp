#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = power(a, b / 2);
  ret = ret * ret % mod;
  if (b & 1) {
    ret = ret * a % mod;
  }
  return ret;
}

int N = 5;
vector<int> p;

int alive(vector<int> x) {
  int ret = 0;
  for (auto it : x) if (it > 0) ret++;
  return ret;
}

void dfs(int i, int max_power) {
  // printf("%d %d\n", i, max_power);
  if (p.size() == N) {
    auto x = p;
    while (alive(x) > 1) {
      // printf("debug: "); for (auto it : x) printf("%d ", it); printf(": %d\n", alive(x));
      int num = 0;
      for (auto it : x) if (it > 0) num++;
      vector<int> to;
      for (auto it : x) {
        to.push_back(it - num + 1);
      }
      x = to;
    }
    if (alive(x)) {
      for (auto it : p) printf("%d ", it); printf(": %d\n", alive(x));
    }
    return;
  }
  for (int x = 1; x <= max_power; x++) {
    p.push_back(x);
    dfs(i + 1, x);
    p.pop_back();
  }
}

int main() {
  for (int i = 6; i <= 8; i++) {
    printf("start %d\n", i);
    p.push_back(i);
    dfs(0, i);
    p.pop_back();
  }
  puts("done");

  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = power(k, n);
  for (int x = 2; x <= k; x++) {
    long long cur = n * power(x - 1, n - 1) % mod;
    ans -= cur;
    if (ans < 0) ans += mod;
  }
  cout << ans << endl;
  return 0;
}
