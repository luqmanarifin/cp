#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int l[N], r[N];
char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  for(int i = 0; i <= n + 1; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  for(int i = 1; i <= n; i++) {
    if(l[i]) {
      if(s[l[i]] != s[i]) {
        r[l[l[i]]] = r[i];
        l[r[i]] = l[l[i]];
      }
    }
  }
  int ans = 0;
  for(int i = r[0]; i <= n; i = r[i]) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
