#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    bool fail = 0, full = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
      fail |= a[i] == 2;
      full |= a[i] == 5;
    }
    if(!fail && full && n * 4 <= sum) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
