#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i*4 <= n; i++) {
    if((n - 4*i) % 7 == 0) {
      for(int it = 0; it < i; it++) {
        printf("4");
      }
      //cout << n - 4*i << endl;
      int t = (n - 4*i) / 7;
      //cout << t << endl;
      while(t--) {
        printf("7");
      }
      return 0;
    }
  }
  puts("-1");
  return 0;
}