#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof(s));
    int inas = 0, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) s[a[i]]++;
    for (int i = n; i >= 1; i--) s[i] += s[i + 1];
    for (int i = 1; i <= n; i++) if (s[i] == 0) inas++;
    cout << inas << endl;
  }
  return 0;
}
