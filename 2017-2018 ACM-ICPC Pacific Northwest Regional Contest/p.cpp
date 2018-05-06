#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long ans[N];
map<long long, long long> cache;
long long last[N];

vector<long long> factors[N];
vector<long long> prime;

long long arith(long long r, long long n) {
  long long ret = 0, now = 1;
  for (int i = 0; i < n; i++) {
    ret += now;
    now *= r;
  }
  return ret;
}

long long solve(long long n, long long a) {
  if (n < N) return ans[n];
  long long ret = 1;
  for (auto it : factors[n - a]) {
    long long f = it;
    int pw = 0;
    while (n % f == 0) {
      pw++;
      n /= f;
    }
    ret = ret * arith(f, pw + 1);
  }
  if (n > 1) {
    ret = ret * arith(n, 2);
  }
  return ret;
}

int main() {
  last[1] = 1;
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      prime.push_back(i);
      for (int j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  ans[1] = 1;
  for (int i = 2; i < N; i++) {
    long long n = i;
    long long f = last[i];
    int pw = 0;
    while (n % f == 0) {
      pw++;
      n /= f;
    }
    ans[i] = ans[n] * arith(f, pw + 1);
  }
  long long a, b;
  cin >> a >> b;
  for (auto it : prime) {
    long long st = a / it * it;
    while (st <= b) {
      if (a <= st) {
        factors[st - a].push_back(it);
      }
      st += it;
    }
  }

  long long ret = 0;
  for (long long i = a; i <= b; i++) {
    ret += solve(i, a);
  }
  cout << ret << endl;
  return 0;
}
