#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
int ok[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  bool now = 0;
  int last = -1;
  for(int i = 0; i < n; i++) {
    if(a[i] == 1) {
      now = 1;
      ok[i] = 1;
      last = i;
    }
    if(i && a[i] == 0 && a[i - 1] == 0) {
      ok[i] = ok[i - 1] = 0;
      now = 0;
    }
    if(now == 1) {
      ok[i] = 1;
    }
  }
  for(int i = last + 1; i < n; i++) {
    ok[i] = 0;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += ok[i];
  }
  cout << ans << endl;
  return 0;
}
