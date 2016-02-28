#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9 + 10;

int a[N];
int f[N];
map<int, int> ada;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(a[i] % k == 0) {
      f[i] = ada[a[i] / k];
    }
    ada[a[i]]++;
  }
  ada.clear();
  long long ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    int to = a[i] * k;
    if(abs(1LL * a[i] * k) < inf) {
      ans += 1LL * f[i] * ada[to];
    }
    ada[a[i]]++;
  }
  cout << ans << endl;
  return 0;
}
