#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') {
        a++;
      } else {
        b++;
      }
    }
    printf("%d\n", abs(a - b));
  }

  return 0;
}
