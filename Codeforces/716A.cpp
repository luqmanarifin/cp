#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int now = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i-1] <= c) {
      now++;
    } else {
      now = 1;
    }
  }
  cout << now << endl;
  return 0;
}
