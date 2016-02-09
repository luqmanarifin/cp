#include <bits/stdc++.h>

using namespace std;

int a, suma, b, sumb;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    if(t == 1) {
      a++;
      suma += u;
    } else {
      b++;
      sumb += u;
    }
  }
  puts(suma >= a * 5? "LIVE" : "DEAD");
  puts(sumb >= b * 5? "LIVE" : "DEAD");
  return 0;
}
