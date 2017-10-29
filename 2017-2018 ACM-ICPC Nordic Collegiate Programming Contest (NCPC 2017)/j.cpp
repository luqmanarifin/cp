#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int maks = max(x, y) * 2;
  if(x == 0 && y == 0){
    puts("Not a moose");
  }
  else{
    printf("%s %d\n", x == y ? "Even" : "Odd", maks);
  }
  return 0;
}
