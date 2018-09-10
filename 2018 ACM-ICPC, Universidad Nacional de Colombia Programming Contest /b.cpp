#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 1e9;

char a[N], b[N];
bool wow[N];
int n;

void rotate() {
  char last = a[n - 1];
  for (int i = n - 1; i >= 1; i--) a[i] = a[i-1];
  a[0] = last;
}

int f1() {
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i-1] != b[i-1]) {
      a[i-1] ^= 1;
      a[i] ^= 1;
      wow[i] = 1;
      ans++;
    }
  }
  int ret = (a[n-1] == b[n-1]? ans : inf);
  for (int i = 1; i < n; i++) {
    if (wow[i]) {
      a[i-1] ^= 1;
      a[i] ^= 1;
      wow[i] = 0;
    }
  }
  return ret;
}

int f2() {
  if (n >= 2) {
    a[n-1] ^= 1; a[0] ^= 1;
    int ret = f1();
    a[n-1] ^= 1; a[0] ^= 1;
    return ret + 1;
  }
  return inf;
}

int main() {
  scanf("%s %s", a, b);
  n = strlen(a);
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, min(f1(), f2()));
    rotate();
  }
  if (ans >= inf) ans = -1;
  cout << ans << endl;
  return 0;
}
