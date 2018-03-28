#include <bits/stdc++.h>

using namespace std;

const int N = 64;
const unsigned long long inf = 1LL << 63;

unsigned long long mul(unsigned long long a, unsigned long long b) {
  if (a == 0 || b == 0) return 0;
  if (inf / a < b) return inf;
  unsigned long long ret = a * b;
  if (ret > inf) ret = inf;
  return ret;
}

unsigned long long C[N][N];
unsigned long long powb(unsigned long long b, unsigned long long p) {
  unsigned long long r = 1;
  for (; p; p >>= 1, b = mul(b, b))
    if(p & 1)
      r = mul(r, b);
  return r;
}

vector<unsigned long long> prime;
unsigned long long ans = inf;

void solve(int sz, int id, int last, unsigned long long n, unsigned long long cur) {
  if (cur >= ans) return;
  if (id >= prime.size()) return;
  if (n == 1) {
    cur = mul(cur, powb(prime[id], sz));
    ans = min(ans, cur);
    return;
  }
  for (int i = min(last, sz); i > 0; --i) {
    if (n % C[sz][i]) continue;
    unsigned long long now = mul(cur, powb(prime[id], i));
    if (now >= ans) continue;
    solve(sz-i, id+1, i, n/C[sz][i], now);
  }
}

int main() {
  for (int i = 2; prime.size() < N; ++i) {
    bool ok = 1;
    for (int j = 2; j *j <= i; ++j)
      if ((i % j) == 0)
        ok = 0;
    if (ok)
      prime.push_back(i);
  }
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
      if (C[i][j] > inf) C[i][j] = inf;
    }
  }
  unsigned long long n;
  while (cin >> n) {
    ans = inf;
    for (int i = 1; i < N; ++i) {
      solve(i,0,i,n,1);
    }
    cout << n << " " << ans << "\n";
  }
  return 0;
}