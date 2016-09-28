#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int BIG = 1e9;

long long power[15];
vector<int> prime;
bool is[N];

long long ten(long long a, int b, long long c) {
  return a * power[b] + c;
}

long long fact(long long a) {
  long long factors = 1;
  for (auto it : prime) {
    if (a % it) continue;
    int cnt = 0;
    while (a % it == 0) {
      cnt++;
      a /= it;
    }
    factors *= cnt + 1;
  }
  if (a != 1) {
    factors *= 2;
  }
  return (factors + 1) / 2;
}

int main() {
  power[0] = 1;
  for (int i = 1; i < 15; i++) power[i] = power[i - 1] * 10;
  for (int i = 2; i * i < BIG; i++) {
    if (!is[i]) {
      prime.push_back(i);
      for (long long j = 1LL * i * i; j * j < BIG; j += i) {
        is[j] = 1;
      }
    }
  }  
  
  for (int len = 1; len <= 9; len++) {
    long long ans = 0;
    int n = (len + 1) / 2;
    for (int i = 1; i < power[n]; i++) {
      if (i % 10 == 0) continue;
      int rem = len / 2;
      long long tmp = i;
      long long now = 0;
      for (int i = 0; i < rem; i++) {
        now = now * 10 + tmp % 10;
        tmp /= 10;
      }
      long long v = now * power[n] + i;
      long long add = fact(v);
      ans += add;
      //printf("%I64d nambah %I64d\n", v, add);
    }
    printf("%I64d, ", ans);
    cerr << len << " " << ans << endl;
  }

  return 0;
}
