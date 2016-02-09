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
  int ans = 0;
  for(int i = 0; i < n; ) {
    int j = i;
    while(j < n && abs(a[j] - a[i]) <= 2) j++;
    ans++;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
