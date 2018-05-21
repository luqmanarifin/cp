#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n / 2; i++) scanf("%d", a + i), a[i]--;
  sort(a, a + n / 2);
  int black = 0, white = 0;
  for (int i = 0; i < n / 2; i++) {
    black += abs(a[i] - i * 2);
    white += abs(a[i] - (i * 2 + 1));
  }
  cout << min(black, white) << endl;
  return 0;
}
