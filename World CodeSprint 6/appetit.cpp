#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int both = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i != k) both += a[i];
  }
  int paid;
  scanf("%d", &paid);
  int asli = both / 2;
  if (paid > asli) {
    printf("%d\n", paid - asli);
  } else {
    puts("Bon Appetit");
  }
  return 0;
}
