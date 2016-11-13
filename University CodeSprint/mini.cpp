#include <bits/stdc++.h>

using namespace std;

const int N = 10;

long long a[N];

int main() {
  int n = 5;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    sum += a[i];
  }
  sort(a, a + n);
  printf("%lld %lld\n", sum - a[n - 1], sum - a[0]);
  return 0;
}
