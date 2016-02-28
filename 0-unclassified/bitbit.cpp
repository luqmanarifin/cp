#include <bits/stdc++.h>

using namespace std;

int main() {
  int a;
  cin >> a;
  for(int i = 31; i >= 0; i--) {
    printf("%d", (a >> i) & 1);
    if(i % 4 == 0) {
      printf(" ");
    }
  }
  printf("\nPage number : %d\n", a / (1 << 12));
  printf("Offset : %d\n", a % (1 << 12));
  return 0;
}