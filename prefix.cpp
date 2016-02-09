#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool is[N];

long long power(long long a, long long b, long long mod) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2, mod);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

long long inv(long long a, long long mod) {
  return power(a, mod - 2, mod);
}

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n;
  scanf("%d", &n);
  if(n == 1) {
    puts("YES");
    puts("1");
  } else if(n == 4) {
    puts("YES");
    puts("1 3 2 4");
  } else if(is[n]) {
    puts("NO");
  } else {
    puts("YES");
    printf("1 ");
    for(int i = 2; i < n; i++) {
      printf("%d ", (int) (1LL * i * inv(i - 1, n) % n));
    }
    printf("%d\n", n);
  }
  return 0;
}
