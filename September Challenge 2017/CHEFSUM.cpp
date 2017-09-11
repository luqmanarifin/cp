#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int mini = 1e9, p = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] < mini) {
        mini = a[i];
        p = i;
      }
    }
    printf("%d\n", p);
  }
  return 0;
}