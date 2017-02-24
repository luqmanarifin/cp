#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char a[N], b[N];
int ca[N], cb[N];

int main() {
  int n;
  scanf("%d %s %s", &n, a, b);
  for (int i = 0; i < n; i++) ca[a[i] - '0']++;
  for (int i = 0; i < n; i++) cb[b[i] - '0']++;
  
  int now = 0, ans = 0;
  for (int i = 0; i <= 9; i++) {
    if (i >= 0) now += ca[i];
    int del = min(now, cb[i]);
    now -= del;
    ans += del;
  }
  printf("%d\n", n - ans);
  
  now = 0; ans = 0;
  for (int i = 0; i <= 9; i++) {
    if (i - 1 >= 0) now += ca[i - 1];
    int del = min(now, cb[i]);
    now -= del;
    ans += del;
  }
  printf("%d\n", ans);
  return 0;
}
