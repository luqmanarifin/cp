#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    puts(c % 2? "Alice" : "Bob");
  }

  return 0;
}
