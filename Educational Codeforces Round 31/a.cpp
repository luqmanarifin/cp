
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    int del = min(t, 86400 - a[i]);
    t -= del;
    if (t == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  } 
  assert(0);
  return 0;
}
