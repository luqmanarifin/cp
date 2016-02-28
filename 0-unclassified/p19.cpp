#include <bits/stdc++.h>

using namespace std;

int a[55];
char s[55];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  scanf("%s", s);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'J' && a[i] > 2) ans++;
    if(s[i] == 'S' && a[i] <= 2) ans++;
  }
  cout << ans << endl;
  return 0;
}
