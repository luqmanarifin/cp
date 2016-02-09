#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 1) {
      puts("0");
    } else if(n == 2) {
      printf("%d\n", m);
    } else {
      printf("%d\n", 2*m + n - 3);
    }
  }
  
  return 0;
}
