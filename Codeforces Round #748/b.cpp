#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

char s[30];

int find(int p, char c) {
  for (int i = p; i >= 0; i--) {
    if (s[i] == c) return i;
  }
  return -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int ans = inf;

    // 00
    int r = find(n - 1, '0');
    int l = find(r - 1, '0');
    if (l >= 0) {
      ans = min(ans, n - l - 2);
    }

    // 25
    r = find(n - 1, '5');
    l = find(r - 1, '2');
    if (l >= 0) {
      ans = min(ans, n - l - 2);
    }

    // 50
    r = find(n - 1, '0');
    l = find(r - 1, '5');
    if (l >= 0) {
      ans = min(ans, n - l - 2);
    }

    // 75
    r = find(n - 1, '5');
    l = find(r - 1, '7');
    if (l >= 0) {
      ans = min(ans, n - l - 2);
    }

    assert(ans != inf);
    printf("%d\n", ans);
  }

  return 0;
}
