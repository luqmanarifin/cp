#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;

long long solve(long long t) {
  for (int i = 0; i < n; i++) {
    t = t / a[i] * a[i];
  }
  return t;
}  

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long l = 2, r = 1e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (solve(mid) >= 2) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  long long lowest = l;
  
  l = 2, r = 1e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (solve(mid) <= 2) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  long long biggest = l;
  if (solve(l) != 2) {
    puts("-1");
  } else {
    printf("%lld %lld\n", lowest, biggest);
  }
  return 0;
}
