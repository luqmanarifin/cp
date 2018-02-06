#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  scanf("%s", s);
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == '0') continue;
    int j = i;
    while (j + 2 < n && s[j + 1] == '1') j++;
    sort(a + i, a + j + 2);
    i = j;
  }
  bool ok = 1;
  for (int i = 0; i + 1 < n; i++) if (a[i] > a[i + 1]) ok = 0;
  puts(ok? "YES" : "NO");
  return 0;
}
