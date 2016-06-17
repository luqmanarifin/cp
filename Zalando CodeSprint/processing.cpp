#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, m;

bool can(long long t) {
  long long ret = 0;
  for(int i = 0; i < m; i++) {
    ret += t / a[i];
    if(ret >= n) return 1;
  }
  return ret >= n;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  long long l = 0, r = 1e18 + 5;
  while(l < r) {
    long long mid = (l + r) >> 1;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}