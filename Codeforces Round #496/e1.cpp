#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], pos[N];
map<int, int> mp;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    pos[a[i]] = i;
  }
  int now = 0;
  for (int i = pos[m]; i <= n; i++) {
    if (a[i] == m) {

    } else if (a[i] > m) {
      now++;
    } else {
      now--;
    }
    mp[now]++;
  }

  long long ans = 0;
  now = 0;
  for (int i = pos[m]; i >= 1; i--) {
    if (a[i] == m) {

    } else if (a[i] > m) {
      now++;
    } else {
      now--;
    }
    ans += mp[-now] + mp[-now + 1];
  }
  cout << ans << endl;
  return 0;
}
