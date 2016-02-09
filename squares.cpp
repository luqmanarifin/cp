#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long mini = 2e9, maks = -2e9;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    mini = min(mini, a[i]);
    maks = max(maks, a[i]);
  }
  long long ans = mini * n;
  if(mini != maks) {
    int pol = 0;
    for(int i = 0; i < 2 * n; i++) {
      while(i < 2 * n && a[i % n] == mini) i++;
      int j = i;
      while(j < 2 * n && a[j % n] != mini) j++;
      pol = max(pol, j - i);
      i = j;
    }
    ans += pol;
  }
  cout << ans << endl;
  return 0;
}
