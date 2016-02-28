#include <bits/stdc++.h>

using namespace std;

int main() {
  int a;
  scanf("%d", &a);
  a--;
  int f = a / 26;
  int s = a % 26;
  if(f > 0) printf("%c", 'A' + f - 1);
  printf("%c\n", 'A' + s);
  return 0;
}
