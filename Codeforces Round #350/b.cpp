#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long sum(int z) {
  return 1LL * z * (z + 1) / 2;
}

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int l = 0, r = n;
  while(l < r) {
    int mid = (l + r + 1) >> 1;
    long long s = sum(mid);
    if(k <= s) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  int rem = k - sum(l);
  printf("%d\n", a[rem - 1]);
  return 0;
}