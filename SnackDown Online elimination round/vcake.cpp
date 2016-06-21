#include <bits/stdc++.h>

using namespace std;

long long gcd(long long num, long long b) {
  return b? gcd(b, num % b) : num;
}

long long num[3];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < 3; i++) scanf("%lld", num + i);
    long long sum = num[0] + num[1] + num[2];
    if(sum > n * m) {
      puts("No");
      continue;
    }

    sort(num, num + 3);
    long long fpb = gcd(num[0], gcd(num[1], num[2]));
    long long p = num[0] / fpb;
    long long q = num[1] / fpb;
    long long r = num[2] / fpb;
    if(n % (p + q + r) == 0) {
      puts("Yes");
      continue;
    }
    if(m % (p + q + r) == 0) {
      puts("Yes");
      continue;
    }
    bool found = 0;
    for(int i = 0; i < 2; i++) {
      sort(num, num + 3);
      do {
        long long a = num[0];
        long long b = num[1];
        long long c = num[2];

        long long s = a + b;
        long long C = c;
        long long f = gcd(s, C);
        s /= f;
        C /= f;
        if(n % (s + C) == 0) {
          long long g = gcd(a, b);
          a /= g;
          b /= g;
          if(m % (a + b) == 0) {
            found = 1;
            goto CONTINUE;
          }
        }

      } while(next_permutation(num, num + 3));
      swap(n, m);
    }
    CONTINUE:;
    puts(found? "Yes" : "No");
  }
  return 0;
}
