#include <bits/stdc++.h>

using namespace std;

int cnt;

int main() {
  int n;
  long long now;
  scanf("%d %lld", &n, &now);
  while (n--) {
    char c; long long v;
    scanf(" %c %lld", &c, &v);
    if (c == '+') {
      now += v;
    } else {
      if (now < v) {
        cnt++;
      } else {
        now -= v;
      }
    }
  }
  printf("%lld %d\n", now, cnt);
  return 0;
}
