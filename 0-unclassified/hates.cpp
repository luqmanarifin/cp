#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], n, m;

bool good(long long t) {
  long long tmp[N];
  for(int i = 1; i <= n; i++) {
    tmp[i] = a[i];
  }
  int i = n;
  for(int it = 0; it < m; it++) {
    while(i > 0 && tmp[i] == 0) {
      i--;
    }
    long long rem = t - i;
    while(i > 0 && rem > 0) {
      long long del = min(rem, tmp[i]);
      rem -= del;
      tmp[i] -= del;
      if(tmp[i] == 0) {
        i--;
      }
    }
  }
  while(i > 0 && tmp[i] == 0) {
    i--;
  }
  return i == 0;
}

int main() {
  scanf("%I64d %I64d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  long long l = 0, r = 1e15;
  while(l < r) {
    long long mid = (l + r) >> 1;
    if(good(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
