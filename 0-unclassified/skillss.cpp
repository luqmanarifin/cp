#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long n, A, cf, cm, m;
pair<long long, int> a[N];
long long ori[N];

long long f(long long t, bool push = 0) {
  long long c = m;
  int at = -1;
  for(int i = 0; i < n; i++) {
    if(a[i].first > t) break;
    long long del = t - a[i].first;
    if(del > c) return -1;
    if(push) {
      ori[a[i].second] = t;
    }
    at = i;
    c -= del;
  }
  if(t == A) return t * cm + cf * n;
  long long ret = t * cm;
  for(int i = n - 1; i > at; i--) {
    if(A - a[i].first <= c) {
      c -= A - a[i].first;
      ret += cf;
      if(push) {
        ori[a[i].second] = A;
      }
    } else {
      break;
    }
  }
  if(cf > cm) {
    for(int i = 0; i <= at; i++) {
      if(A - t <= c) {
        if(push) {
          ori[a[i].second] = A;
        }
        c -= A - t;
        ret += cf;
      } else {
        break;
      }
    }
  }
  return ret;
}

int main() {
  scanf("%I64d %I64d %I64d %I64d %I64d", &n, &A, &cf, &cm, &m);
  long long mini = inf;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", ori + i);
    mini = min(mini, ori[i]);
    a[i] = {ori[i], i};
  }
  sort(a, a + n);
  long long l = mini, r = A;
  while(r - l > 3) {
    long long lf = l + (r - l) / 3;
    long long rf = r - (r - l) / 3;
    if(f(lf) < f(rf)) {
      l = lf;
    } else {
      r = rf;
    }
  }
  long long ans = -inf;
  long long p = -1;
  for(long long i = l; i <= r; i++) {
    long long cur = f(i);
    if(cur > ans) {
      ans = cur;
      p = i;
    }
  }
  f(p, 1);
  printf("%I64d\n", ans);
  for(int i = 0; i < n; i++) {
    printf("%I64d ", ori[i]);
  }
  //for(int i = 0; i <= A; i++) printf("%d %I64d\n", i, f(i));
  return 0;
}
