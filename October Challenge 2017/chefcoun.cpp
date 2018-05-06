
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
    a[0] = 1;
    a[1] = 2;

    long long tot = (1LL << 32) - 5;
    for (int i = 2; i < n; i++) a[i] = tot / (n - 2);
    int rem = tot % (n - 2);
    for (int i = n - 1; i >= n - rem; i--) a[i]++;

    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", a[i]);
    } 
    printf("\n");
  }

  return 0;
}
