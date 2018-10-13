#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 998244353;

int bit[N];

void add(int i) {
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    bit[i]++;
  }
}

int find(int i) {
  int ret = 0;
  for (; i < N; i |= i + 1) ret += bit[i];
  return ret;
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

char a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d %s %s", &n, &m, a, b);
  reverse(a, a + n);
  reverse(b, b + m);
  for (int i = 0; i < m; i++) if (b[i] == '1') {
    add(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      long long now = power(2, i);
      long long ada = find(i);
      ans += now * ada % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
