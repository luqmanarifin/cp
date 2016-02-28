#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<int> num;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  for(int i = 1; i < n; i++) {
    num.push_back(a[i] - a[i - 1]);
  }
  if(num.empty()) {
    cout << 0 << endl;
    return 0;
  }
  int now = num[0];
  for(int i = 1; i < num.size(); i++) {
    now = __gcd(now, num[i]);
  }
  int ans = 0;
  for(int i = 0; i < num.size(); i++) {
    ans += num[i] / now - 1;
  }
  cout << ans << endl;
  
  return 0;
}
