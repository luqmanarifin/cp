// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    p[a] = i;
  }
  long long ans = 0;
  for(int i = 2; i <= n; i++) {
    ans += abs(p[i] - p[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
