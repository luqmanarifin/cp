#include <bits/stdc++.h>

using namespace std;

int s[] = {500, 1000, 1500, 2000, 2500};

int m[10], w[10];

int main() {
  int a, b;
  for(int i = 0; i < 5; i++) {
    scanf("%d", m + i);
  }
  for(int i = 0; i < 5; i++) {
    scanf("%d", w + i);
  }
  scanf("%d %d", &a, &b);
  int ans = 0;
  for(int i = 0; i < 5; i++) {
    ans += max(s[i] * 3 / 10, s[i] - s[i] * m[i] / 250 - 50 * w[i]);
  }
  ans += 100 * a - 50 * b;
  cout << ans << endl;
  return 0;
}
