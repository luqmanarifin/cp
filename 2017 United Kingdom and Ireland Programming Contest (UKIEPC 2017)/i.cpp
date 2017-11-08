#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int t;
  scanf("%d", &t);
  int p = -1, ans = 1e9;
  for (int i = 0; i < n; i++) {
    if (t % a[i] < ans) {
      ans = t % a[i];
      p = a[i];
    }
  }
  cout << p << endl;
  return 0;
}
