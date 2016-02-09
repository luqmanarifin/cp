#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    swap(a[0], a[1]);
    for(int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  
  return 0;
}
