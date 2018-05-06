
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

int main() {
  int n, A, B;
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 0; i < n; i++) a[i] = i;
  int sisa_n = n - B;
  int cluster = A - 1;
  int k = sisa_n / B + (sisa_n % B? 1 : 0);
  if (k <= cluster && cluster <= sisa_n) {
    reverse(a + n - B, a + n);
    int now = n - B;
    int makan = sisa_n - cluster;
    while (makan > 0) {
      int del = min(B - 1, makan);
      //printf("makan %d del %d\n", makan, del);
      //printf("rev %d %d\n", now - del - 1, now - 1);
      reverse(a + now - del - 1, a + now);
      makan -= del;
      now -= del + 1;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i] + 1);
  } else {
    puts("-1");
  }

  return 0;
}
