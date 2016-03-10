#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, int>> p;
char junk[105];

long long find(long long full, long long s) {
  return full / s + (full % s? 1 : 0);
}

// a-b orang, c-d musuh
bool solve(long long a, long long b, long long c, long long d) {
  return find(a, d) >= find(c, b);
}

int main() {
  int sd, td, ls, lt, n;
  scanf("%s %d %d %d %d %d", junk, &sd, &td, &ls, &lt, &n);
  long long sa, ta;
  scanf("%lld %lld", &sa, &ta);
  long long l = 0, r = 1e9;
  while(l < r) {
    long long mid = (l + r) >> 1;
    if(solve(sd + mid * ls, td + mid * lt, sa, ta)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if(l > n - 1) {
    puts("-1");
    return 0;
  }
  int need = l;
  for(int i = 2; i <= n; i++) {
    scanf("%lld %lld", &sa, &ta);
    long long l = 0, r = 1e9;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(solve(sd + mid * ls, td + mid * lt, sa, ta)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    p.emplace_back(l, i);
  }
  sort(p.begin(), p.end());
  for(int i = 0; i < need; i++) {
    if(p[i].first > i) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", need);
  for(int i = 0; i < need; i++) {
    printf("%d\n", p[i].second);
  }
  return 0;
}
