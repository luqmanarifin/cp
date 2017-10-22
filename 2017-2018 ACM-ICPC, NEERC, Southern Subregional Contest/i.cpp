#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, k;
int v[N], ok[N];

bool can(int x) {
  ok[0] = 1;
  for (int i = 0, a = 0, cnt = 0; i < n; i++) {
    if (i-k+1 >= 0)
      cnt += ok[i-k+1];
    while (a <= i-k+1 && v[i] - v[a] > x) cnt -= ok[a], a++;
    ok[i+1] = cnt > 0;
  }
  return ok[n];
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", v+i);
  }
  sort(v, v+n);
  int l = 0, r = v[n-1];
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
