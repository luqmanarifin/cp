#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int sum;
  scanf("%d %s", &sum, s);
  int n = strlen(s);
  int now = 1;
  for(int i = 0; i < n; i++) {
    if(sum < now) {
      printf("%d\n", sum);
      return 0;
    }
    if(s[i] == 'W') {
      sum += now;
      now = 1;
    } else {
      sum -= now;
      now *= 2;
    }
  }
  printf("%d\n", sum);
  return 0;
}
