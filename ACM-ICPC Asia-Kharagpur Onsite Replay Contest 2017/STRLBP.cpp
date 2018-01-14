#include <bits/stdc++.h>

using namespace std;

const int N = 10;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = 8, ans = s[0] != s[n - 1];
    for (int i = 1; i < n; i++) ans += s[i] != s[i - 1];
    puts(ans <= 2? "uniform" : "non-uniform");
  }
  return 0;
}
