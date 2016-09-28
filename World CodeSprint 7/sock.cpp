#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int c;
    scanf("%d", &c);
    cnt[c]++;
  }
  int ans = 0;
  for (int i = 0; i < 105; i++) ans += cnt[i] / 2;
  cout << ans << endl;
  
  return 0;
}