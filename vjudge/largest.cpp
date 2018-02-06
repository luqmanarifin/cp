#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int last[N];
vector<long long> p;

long long solve(long long n) {
  int primes = 0;
  long long ans = 0;
  for (auto it : p) {
    if (1LL * it * it > n) break;
    int ada = 0;
    while (n % it == 0) {
      n /= it;
      ada++;
    }
    if (ada) {
      primes++;
      ans = it;
    }
  }
  if (n > 1) {
    primes++;
    ans = n;
  }
  if (primes <= 1) ans = -1;
  return ans;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!last[i]) {
      p.push_back(i);
      for (long long j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  //cout << p.size() << endl;
  //for (int i = 2; i <= 10; i++) printf("%d: %d\n", i, last[i]);
  
  long long n;
  while (1) {
    scanf("%lld", &n);
    if (n == 0) break;
    if (n < 0) n *= -1;
    printf("%lld\n", solve(n));
  }
  
  return 0;
}
