#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if(a < d) {
      puts("Player1");
    } else if(a > d) {
      puts("Player2");
    } else if(b < e) {
      puts("Player1");
    } else if(b > e) {
      puts("Player2");
    } else if(c < f) {
      puts("Player1");
    } else if(c > f) {
      puts("Player2");
    } else {
      puts("Tie");
    }
  }
  return 0;
}