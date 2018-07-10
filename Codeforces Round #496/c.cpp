#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

map<int, int> mp;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mp[a[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ada = 0;
    for (int j = 30; (1 << j) >= a[i]; j--) {
      int other = (1 << j) - a[i];
      if (other == a[i]) {
        if (mp[other] > 1) {
          ada = 1;
          break;
        }
      } else {
        if (mp[other]) {
          ada = 1;
          break;
        }
      }
    }
    if (!ada) ans++;
  }
  cout << ans << endl;
  return 0;
}
