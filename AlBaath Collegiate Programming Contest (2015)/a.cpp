#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int g, y, r;
    long long a;
    scanf("%I64d %d %d %d", &a, &g, &y, &r);
    a++;
    long long tot = g + y + r;
    a %= tot;
    if(a == 0) a += tot;
    if(a <= g) {
      puts("GREEN");
    } else if(a <= g + y) {
      puts("YELLOW");
    } else {
      puts("RED");
    }
  }
  return 0;
}
