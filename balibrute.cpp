#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = 4e18;

int num[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }
  
  int pol = (1 << n);
  long long ans = inf;
  for(int mask = 0; mask < pol; mask++) {
    if(mask % 2 == 0) continue;
    int pop = __builtin_popcount(mask);
    if(a <= pop && pop <= b) {
      long long temp = 0;
      long long sum = 0;
      for(int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          temp |= sum;
          sum = num[i];
        } else {
          sum += num[i];
        }
      }
      temp |= sum;
      ans = min(ans, temp);
    }
  }
  cout << ans << endl;
  return 0;
}
