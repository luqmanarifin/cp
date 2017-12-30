#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long mod = 1e9 + 7;

long long d[N][N], p[N][N];
int k, pa, pb;
long long inv_pb, inv_pa_pb;
bool vis[N][N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) temp = temp * a % mod;
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

pair<long long, long long> dfs(int gain, int A) {
  if (vis[gain][A]) return {d[gain][A], p[gain][A]};
  if (A == 0) return dfs(gain, A + 1);
  if (A == k) return {(A * pb + pa) % mod, pb};
  if (gain >= k) return {0, 1};
  vis[gain][A] = 1;
  auto QR = dfs(gain, A + 1);
  auto ST = dfs(gain + A, A);
  long long Q = QR.first, R = QR.second;
  long long S = ST.first, T = ST.second;
  d[gain][A] = (pa*Q%mod*T%mod + pb*R%mod*(S + A*T%mod)%mod) % mod;
  p[gain][A] = (pa + pb) * R % mod * T % mod;
  return {d[gain][A], p[gain][A]};
}

int main() {
  cout << (2 * inv(3) + 5 * inv(6)) % mod << endl;
  cout << (3 * inv(2) % mod) << endl;
  cout << (11 * inv(2) - 4) % mod<< endl;
  return 0;
}
