#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%.15f\n", (double) ((1LL << n) - 1) * p / 100);
  }
  return 0;
}
