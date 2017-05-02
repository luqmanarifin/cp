#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}
 
long long a[N];

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
  for (int i = 1; i < N; i++) ifact[i] = inv(fact[i]);
  
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  set<int> id;
  for (int i = 0; i < n; i++) id.insert(i);
  for (int j = 62; j >= 0; j--) {
    int cnt = 0;
    for (auto it : id) {
      if (a[it] & (1LL << j)) {
        cnt++;
      }
    }
    if (cnt >= k) {
      vector<int> rem;
      for (auto it : id) {
        if ((a[it] & (1LL << j)) == 0) {
          rem.push_back(it);
        }
      }
      for (auto it : rem) id.erase(it);
    }
  }
  long long ans = -1;
  for (auto it : id) ans &= a[it];
  cout << ans << endl;
  cout << c(id.size(), k) << endl;
  return 0;
}
