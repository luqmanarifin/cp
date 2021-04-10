#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int P = 505;

long long prime[N];

vector<int> f;

vector<long long> factorize(long long n) {
  vector<long long> res;
  if (n == 1) return res;
  for (auto it : f) {
    while (n % it == 0) {
      res.push_back(it);
      n /= it;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}

vector<pair<long long, int>> get(long long n) {
  // printf("get %lld\n", n);
  auto primes = factorize(n);
  sort(primes.begin(), primes.end());
  vector<pair<long long, int>> res;
  for (int i = 0; i < primes.size(); i++) {
    int j = i;
    while (j + 1 < primes.size() && primes[j + 1] == primes[j]) j++;
    res.emplace_back(primes[i], j - i + 1);
    i = j;
  }
  return res;
}

long long own[P];

int main() {
  for (int i = 2; i < N; i++) {
    if (prime[i]) continue;
    if (i < 500) {
      f.push_back(i);
    }
    for (int j = i; j < N; j += i) prime[j] = i; 
  }
  // puts("asu");
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(own, 0, sizeof(own));

    int m;
    scanf("%d", &m);
    long long sum = 0;
    while (m--) {
      int k;
      long long v;
      scanf("%d %lld", &k, &v);
      own[k] = v;
      sum += 1LL * k * v;
    }
    long long answer = 0;
    for (long long ans = sum; ans >= sum - 64 * 499 && ans >= 2; ans--) {
      // printf("verifying %lld\n", ans);
      auto factors = get(ans);
      // printf("factorization finished %lld\n", ans);
      bool can = 1;
      long long sum_factors = 0;
      for (auto it : factors) {
        if (it.first >= P) {
          can = 0;
          break;
        }
        if (it.second > own[it.first]) {
          can = 0;
          break;
        }
        sum_factors += it.first * it.second;
      }
      if (can && sum_factors == sum - ans) {
        answer = ans;
        break;
      }
    }
    printf("Case #%d: %lld\n", tt, answer);
  }

  return 0;
}
