#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int nol = 0, one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        nol++;
      } else {
        one++;
      }
    }
    if (nol == n - 1 || one == n - 1) {
      puts("Yes");
    } else {
      puts("No");
    }
  }

  return 0;
}
