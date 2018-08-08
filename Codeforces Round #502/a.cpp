#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

pair<int, int> v[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int sum = a + b + c + d;
    v[i] = make_pair(sum, -i);
  }
  sort(v, v + n);
  reverse(v, v + n);
  for (int i = 0; i < n; i++) {
    if (v[i].second == 0) {
      cout << i + 1 << endl;
    }
  }

  return 0;
}
