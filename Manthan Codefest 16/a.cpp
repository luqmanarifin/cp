#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for(int i = 0; i * a <= c; i++) {
    int p = c - i * a;
    if(p % b == 0) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
