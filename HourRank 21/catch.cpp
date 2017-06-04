#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];
int v[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  int p = 0, ada = 1;
  for (int i = 1; i < n; i++) {
    int di = abs(a[i] - x);
    int dp = abs(a[p] - x);
    if (di * v[p] < dp * v[i]) {
      p = i;
      ada = 1;
    } else if (di * v[p] == dp * v[i]) {
      ada++;
    }
  }
  if (ada > 1) {
    puts("-1");
  } else {
    cout << p << endl;
  }
  return 0;
}
