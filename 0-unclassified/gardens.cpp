#include <bits/stdc++.h>

using namespace std;

const int N = 15005;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int now = 0;
  for(int i = 1; i <= n; ) {
    if(i + 1 <= n && a[i]) {
      now += a[i] + a[i + 1];
      i += 2;
    } else {
      now += a[i];
      i++;
    }
    if(k <= 0) break;
    k--;
  }
  cout << now << endl;
  return 0;
}
