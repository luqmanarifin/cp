#include <bits/stdc++.h>

using namespace std;

int get(int v) {
  if (v == 1) return 1;
  if (v == 2) return 0;
  if (v % 2) return 1;
  return 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int nim = 0;
    while (n--) {
      int m, k;
      scanf("%d %d", &m, &k);
      nim ^= get(m);
    }
    puts(nim == 0? "BEN" : "BOB");
  }
  return 0;
}
