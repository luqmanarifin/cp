#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int pol = (n / 2 + n % 2) * (n / 2 + n % 2) + (n / 2) * (n / 2);
  if(pol < k) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(k && (i + j) % 2 == 0) {
        printf("L");
        k--;
      } else {
        printf("S");
      }
    }
    printf("\n");
  }
  
  return 0;
}
