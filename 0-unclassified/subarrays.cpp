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
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      int j = i;
      while(j + 1 < n && a[j] <= a[j + 1]) j++;
      int len = j - i + 1;
      ans += 1LL * len * (len + 1) / 2;
      i = j;
    }
    cout << ans << endl;
  }
  
  return 0;
}
