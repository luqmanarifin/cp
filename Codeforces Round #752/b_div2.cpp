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
    bool increasing = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (a[i - 1] >= a[i]) {
        increasing = 0;
      }
    }
    puts(n % 2 && increasing? "NO" : "YES");
  }

  return 0;
}
