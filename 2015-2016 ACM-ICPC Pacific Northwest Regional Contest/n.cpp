#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int safe = 1, pecah = k;
  while(n--) {
    int v;
    scanf("%d %s", &v, s);
    if(s[0] == 'S') {
      safe = max(safe, v);
    } else {
      pecah = min(pecah, v);
    }
  }
  if(safe + 1 == pecah) {
    printf("%d %d\n", pecah, safe);
  } else {
    printf("%d %d\n", safe + 1, pecah - 1);
  }
  return 0;
}