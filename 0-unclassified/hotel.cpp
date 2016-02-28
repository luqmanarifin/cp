// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

pair<int, int> a[N];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  reverse(a, a + n);
  int now = s, ans = 0;
  for(int i = 0; i < n; i++) {
    if(a[i].first != now) {
      ans += abs(a[i].first - now);
      now = a[i].first;
    }
    if(a[i].second > ans) {
      ans = a[i].second;
    }
  }
  ans += now;
  cout << ans << endl;
  return 0;
}
