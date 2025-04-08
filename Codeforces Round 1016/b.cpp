#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    bool done = 0; int p = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '0') {
        done = 1;
      } else {
        if (done) {
          p++;
        }
      }
    }
    printf("%d\n", n - p - 1);
  }

  return 0;
}
