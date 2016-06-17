#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s %s", a, b);
    int n = strlen(a);
    int zero = 0, one = 0;
    bool zeroGood = 0, oneGood = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] == '0') {
        if(b[i] == '0') {
          zeroGood = 1;
        } else {
          zero++;
        }
      } else {
        if(b[i] == '0') {
          one++;
        } else {
          oneGood = 1;
        }
      }
    }
    if(one && zero == 0 && !zeroGood) {
      puts("Unlucky Chef");
      continue;
    }
    if(zero && one == 0 && !oneGood) {
      puts("Unlucky Chef");
      continue;
    }
    puts("Lucky Chef");
    printf("%d\n", max(one, zero));
  }
  return 0;
}