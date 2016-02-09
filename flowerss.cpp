#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

long long a[N], b[N], p, q;
bool done[N];
int n;

long long dist(long long e, long long f, long long g, long long h) {
  return (e - g)*(e - g) + (f - h)*(f - h);
}

long long e, f;

long long solve(long long t) {
  memset(done, 0, sizeof(done));
  for(int i = 0; i < n; i++) {
    if(dist(a[i], b[i], e, f) <= t) {
      done[i] = 1;
    }
  }
  long long add = 0;
  for(int i = 0; i < n; i++) {
    if(!done[i]) {
      add = max(add, dist(a[i], b[i], p, q));
    }
  }
  return t + add;
}

int main() {
  scanf("%d %I64d %I64d %I64d %I64d", &n, &e, &f, &p, &q);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", a + i, b + i);
  }
  long long l = 0, r = 1e15;
  while(r - l > 3) {
    long long lf = l + (r - l)/3;
    long long rf = r - (r - l)/3;
    if(solve(lf) < solve(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  long long ans = 1e15;
  for(long long i = l; i <= r; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;
  return 0;
}
