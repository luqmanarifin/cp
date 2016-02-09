#include <bits/stdc++.h>

using namespace std;

long long ten[16];

template <class T>
inline std::string to_string (const T& t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

int dig(long long a) {
  int ret = 1;
  while(a > 9) {
    ret++;
    a /= 10;
  }
  return ret;
}

long long ambil(long long a, int i) {
  return a / ten[i] % 10;
}

long long balik(long long a) {
  string rev = to_string(a);
  reverse(rev.begin(), rev.end());
  long long ret = atoll(rev.c_str());
  return ret;
}

int get(long long a, long long b) {
  if(a > b) {
    return 0;
  }
  int n = dig(a);
  long long from = ten[n - 1];
  for(int i = 0; i < n / 2; i++) {
    from += ambil(b, n - 1 - i) * ten[i];
  }
  long long to = balik(from);
  return from - a + b - to + (from != to);
}

int main() {
  ten[0] = 1;
  for(int i = 1; i < 16; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  
  int t = 1;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    long long n = 10000000000001;
    scanf("%I64d", &n);
    int digit = dig(n);
    long long ans = 0;
    for(int i = 0; i < digit - 1; i++) {
      ans += get((i? ten[i] : 0), ten[i + 1] - 1) + 1;
    }
    int rem = 0;
    if(ambil(n, 0) == 0) {
      rem = 1;
    }
    if(n != (digit - 1? ten[digit - 1] : 0)) {
      ans += get((digit - 1? ten[digit - 1] : 0), n - rem) + rem;
    }
    printf("Case #%d: %I64d\n", tt, ans);
  }
  return 0;
}
