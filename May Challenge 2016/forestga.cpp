#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long h[N], ri[N], w, lim;
int n;

bool can(long long t) {
  long long rem = w;
  for(int i = 0; i < n; i++) {
    long long valid = (h[i] >= lim? 0 : (lim - h[i])/ri[i] + ((lim - h[i])%ri[i]? 1 : 0));
    if(valid > t) continue;
    
    if(h[i] >= rem) return 1;
    long long to = (rem - h[i])/ri[i] + ((rem - h[i])%ri[i]? 1 : 0);
    if(to <= t) return 1;
    rem -= h[i] + t * ri[i];
  }
  return rem <= 0;
}

int main() {
  scanf("%d %lld %lld", &n, &w, &lim);
  for(int i = 0; i < n; i++) {
    scanf("%lld %lld", h + i, ri + i);
  }
  long long l = 0, r = 1e18;
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