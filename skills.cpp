#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0;
  vector<int> num;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ans += a[i] / 10;
    if(a[i] % 10) {
      num.push_back(10 - a[i] % 10);
      a[i] += 10 - a[i] % 10;
    } 
    while(a[i] < 100) {
      num.push_back(10);
      a[i] += 10;
    }
  }
  sort(num.begin(), num.end());
  for(int i = 0; i < num.size() && k >= num[i]; i++) {
    ans++;
    k -= num[i];
  }
  cout << ans << endl;
  return 0;
}
