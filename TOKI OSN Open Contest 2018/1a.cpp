#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long solve_kosong(vector<int> p, vector<int> q, int mid) {
  int b = lower_bound(p.begin(), p.end(), mid) - p.begin();
  int a = p.size() - b;
  int d = lower_bound(q.begin(), q.end(), mid) - q.begin();
  int c = q.size() - d;
  if (a == d && c == b) {
    return fact[a] * fact[c] % mod;
  } else {
    return 0;
  }
}

long long solve_satu(vector<int> p, vector<int> q, int mid) {
  int b = lower_bound(p.begin(), p.end(), mid) - p.begin();
  int a = p.size() - b - 1;
  int d = lower_bound(q.begin(), q.end(), mid) - q.begin();
  int c = q.size() - d;
  if (c >= 1) {
    if (p[c - 1] > mid) {
      return 0;
    }
  }
  if (c < p.size()) {
    if (p[c] < mid) {
      return 0;
    }
  }
  return fact[c] * fact[d] % mod;
}

long long solve_both(vector<int> p, vector<int> q, int mid) {
  int b = lower_bound(p.begin(), p.end(), mid) - p.begin();
  int a = p.size() - b - 1;
  int d = lower_bound(q.begin(), q.end(), mid) - q.begin();
  int c = q.size() - d - 1;

  // printf("%d %d %d %d\n", a, b, c, d);

  long long ret = 0;
  // tengah ga kepake
  if (a == d) {
    ret += fact[a] * fact[c + 1];
  } else if (a + 1 == d) {
    ret += fact[a + 1] * fact[p.size() - a - 1];
  }
  ret %= mod;

  // tengah kepake
  if (a >= 1) {
    if (a == d) {
      long long cur = a * fact[a] % mod * fact[c] % mod;
      ret += cur;
    } else if (a == d + 1) {
      ret += fact[a] * fact[c] % mod;
    }
  }
  ret %= mod;

  return ret;
}

bool ada(vector<int> q, int mid) {
  int at = lower_bound(q.begin(), q.end(), mid) - q.begin();
  return (at < q.size() && q[at] == mid);
}

long long solve(vector<int> p, vector<int> q, int mid) {
  if (ada(q, mid)) {
    swap(p, q);
  }
  bool p_ada = ada(p, mid);
  bool q_ada = ada(q, mid);
  if (!p_ada && !q_ada) {
    return solve_kosong(p, q, mid);
  } else if (!q_ada) {
    return solve_satu(p, q, mid);
  } else {
    return solve_both(p, q, mid);
  }
  assert(0);
}

int h[N], a[N], b[N];
vector<int> nump[N], numq[N];
char junk[20];

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int n, k;
  scanf("%s %d %d", junk, &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", h + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    nump[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    numq[b[i]].push_back(i);
  }

  long long ans = 1;
  for (int i = 1; i <= k; i++) {
    ans *= solve(nump[i], numq[i], h[i]);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
