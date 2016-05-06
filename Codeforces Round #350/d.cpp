#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k;
long long a[N], b[N];

bool can(long long t) {
  long long all = 0;
  for(int i = 0; i < n; i++) {
    long long need = 1LL * t * a[i];
    if(b[i] < need) {
      all += need - b[i];
    }
    if(all > k) return 0;
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%I64d", b + i);
  }
  long long l = 0, r = 2e9;
  while(l < r) {
    //cout << l << endl;
    long long mid = (l + r + 1) >> 1;
    if(can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%I64d\n", l);
  return 0;
}