#include <bits/stdc++.h>

using namespace std;

int a[55];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i++) {
    if(sum == 0) {
      printf("%d\n", i);
      return 0;
    }
    sum = max(0, sum - a[i]);
  }
  printf("%d\n", n);
  return 0;
}
