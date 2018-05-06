
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int main() {
  srand(time(0));
  int n = 300000;
  for (int i = 0; i < n; i++) printf("%c", 'a' + rand() % 26); printf("\n");
  int q = 300000;
  printf("%d\n", q);
  while (q--) {
    int t = rand() % 3 + 1;
    int l = rand() % n + 1, r = rand() % n + 1;
    if (l > r) swap(l, r);
    int len = r - l + 1;
    int k = rand() % (n - len + 1) + 1;
    if (t <= 2) {
      printf("%d %d %d %d\n", t, l, r, k);
    } else {
      printf("%d %d %d\n", t, l, r);
    }
  }  
  return 0;
}
