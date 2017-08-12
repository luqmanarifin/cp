#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ada4 = n, ada2 = 2 * n, ada1 = 0;
  int need3 = 0, need2 = 0, need1 = 0;
  for (int i = 0; i < k; i++) {
    int v;
    scanf("%d", &v);
    int del4 = min(ada4, v / 4);
    ada4 -= del4;
    v -= 4 * del4;
    
    int del2 = min(ada2, v / 2);
    ada2 -= del2;
    v -= 2 * del2;
    
    if (v == 3) {
      need3++;
    } else if (v == 2) {
      need2++;
    } else if (v == 1) {
      need1++;
    } else {
      if (v >= 4) {
        puts("NO");
        return 0;
      }
      assert(v == 0);
    }
  }
  {
    int del4 = min(ada4, need3);
    ada4 -= del4;
    need3 -= del4;
    
    int del2 = min(ada2, need3);
    ada2 -= del2;
    need3 -= del2;
    need1 += del2;
  }
  {
    int del4 = min(ada4, need2);
    ada4 -= del4;
    need2 -= del4;
    ada1 += del4;
    
    int del2 = min(ada2, need2);
    ada2 -= del2;
    need2 -= del2;
    
    int del1 = min(ada1, need2 * 2);
    ada1 -= del1;
    need1 += need2 * 2 - del1;
    need2 = 0;
  }
  {
    int del4 = min(ada4 * 2, need1);
    ada4 -= (del4 + 1) / 2;
    need1 -= del4;
    
    int del2 = min(ada2, need1);
    ada2 -= del2;
    need1 -= del2;
    
    int del1 = min(ada1, need1);
    ada1 -= del1;
    need1 -= del1;
  }
  if (need3 == 0 && need2 == 0 && need1 == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
