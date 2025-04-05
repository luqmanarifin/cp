#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

long long fpb(long long a, long long b) {
  if (a == 0) return b;
  return b? fpb(b, a % b) : a;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
    }
    sort(a, a + n);
    long long now = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] % a[0] == 0) {
        now = fpb(now, a[i]);
      }
    }
    puts(now == a[0]? "Yes" : "No");
  }

  return 0;
}
