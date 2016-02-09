#include <bits/stdc++.h>

using namespace std;

const int N = 555;
const int inf = 1e9;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < 2 * n - 1; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  int ans = sum;
  sort(a, a + 2 * n - 1);
  if(n % 2) {
    sum = 0;
    for(int i = 0; i < 2 * n - 1; i++) {
      sum += abs(a[i]);
    }
    ans = sum;
  } else {
    for(int i = 1; i < 2 * n - 1; i += 2) {
      sum -= a[i] + a[i - 1];
      sum += -a[i] - a[i - 1];
      ans = max(sum, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
