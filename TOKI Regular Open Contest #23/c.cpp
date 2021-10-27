#include <bits/stdc++.h>

using namespace std;

const int N = 26;

long long por[N];
long long sum[N];

int main() {
  por[0] = 1;
  for (int i = 1; i < N; i++) {
    por[i] = por[i - 1] * 5;
    sum[i] = sum[i - 1] + por[i - 1];
    // printf("por %lld sum %lld\n", por[i], sum[i]);
  }
  long long n;
  scanf("%lld", &n);
  for (int i = N - 1; i >= 0; i--) {
    long long l = por[i] - sum[i];
    long long r = por[i] + sum[i];
    if (l <= n && n <= r) {
      n -= por[i];
      // printf("remove %lld\n", por[i]);
    } else if (-r <= n && n <= -l) {
      n += por[i];
      // printf("add %lld\n", por[i]);
    }
  }
  puts(n == 0? "YES" : "NO");
  return 0;
}
