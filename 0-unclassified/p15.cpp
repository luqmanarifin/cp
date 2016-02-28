#include <bits/stdc++.h>

using namespace std;

int a[55];

int main() {
  int n;
  scanf("%d", &n);
  int maxi = -1;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    maxi = max(maxi, a[i]);
  }
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d", a[i] * 100 / maxi);
  }
  printf("\n");
  return 0;
}
