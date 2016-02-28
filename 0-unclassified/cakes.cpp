#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int g = __gcd(n, m);
    if(g == 1) {
      puts("Yes");
    } else {
      printf("No %d\n", n / g);
    }
  }
  return 0;
}
