#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

long long find(long long v) {
  return 1LL * v * (v + 1) / 2;
}

long long find(long long l, long long r) {
  return find(r) - (l? find(l - 1) : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    long long from, to;
    scanf("%d %I64d %I64d", &n, &from, &to);
    to--;
    long long len = to - from + 1;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%I64d", a + i);
      sum += a[i];
    }
    long long ans = 0;
    long long halves = 0;
    if(from / sum == to / sum) {
      from %= sum;
      to %= sum;
      from++;
      to++;
      long long now = 0;
      for(int i = 0; i < n; i++) {
        if(from <= now + a[i] && now + 1 <= to) {
          ans += find(max(from, now + 1) - now - 1, min(to, now + a[i]) - now - 1);
          halves += (min(to, now + a[i]) - now - 1) - (max(from, now + 1) - now - 1) + 1;
        }
        now += a[i];
      }
    } else {
      long long lef = (from / sum + (from % sum? 1 : 0)) * sum;
      long long rig = (to + 1) / sum * sum;
      long long strip = (rig - lef) / sum;
      for(int i = 0; i < n; i++) {
        ans += find(0, a[i] - 1) * strip;
        halves += a[i] * strip;
      }
      if(from % sum != 0) {
        from %= sum;
        from++;
        long long now = 0;
        for(int i = 0; i < n; i++) {
          if(from <= now + a[i]) {
            ans += find(max(from, now + 1) - now - 1, a[i] - 1);
            halves += (a[i] - 1) - (max(from, now + 1) - now - 1) + 1;
          }
          now += a[i];
        }
      }
      if(to % sum != sum - 1) {
        to %= sum;
        to++;
        long long now = 0;
        for(int i = 0; i < n; i++) {
          if(now + 1 <= to) {
            ans += find(0, min(to, now + a[i]) - now - 1);
            halves += (min(to, now + a[i]) - now - 1) - (0) + 1;
          }
          now += a[i];
        }
      }
    }
    printf("Case #%d: %.18f\n", tt, (double) ans / len + (double) halves / (2*len));
  }
  
  return 0;
}
