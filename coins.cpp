#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  if(n < 3) {
    puts("-1");
    return 0;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for(int i = n; i >= 2; i--) {
    if(a[i] == 0) {
      continue;
    }
    int base = i % 2? (i - 1) / 2 : i / 2;
    int s = i % 2? i - 1 : i + 1;
    if(s > n) {
      puts("-1");
      return 0;
    }
    int del = max(a[s], a[i]);
    ans += del;
    a[s] = max(a[s] - del, 0);
    a[i] = max(a[i] - del, 0);
    a[base] = max(a[base] - del, 0);
  }
  cout << ans + a[1] << endl;
  return 0;
}
