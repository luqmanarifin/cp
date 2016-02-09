#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(i && a[i] == a[i - 1]) {
      continue;
    }
    int cnt = 0, j = i;
    while(a[j] == a[i]) {
      j++;
      cnt++;
    }
    if(cnt > a[i]) {
      puts("-1");
      return 0;
    }
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
