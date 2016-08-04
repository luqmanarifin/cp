#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int now = 1;
  for (int i = 1; now < N; i++) {
    int v = i;
    vector<int> p;
    while (v) {
      p.push_back(v % 10);
      v /= 10;
    }
    reverse(p.begin(), p.end());
    for (auto it : p) {
      if (now < N) a[now++] = it;
    }
  }
  int n;
  scanf("%d", &n);
  printf("%d\n", a[n]);
  return 0;
}
