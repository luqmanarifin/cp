#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool ada[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  while (n--) {
    int v;
    scanf("%d", &v);
    ada[v] = 1;
  }
  int ans = ada[x];
  for (int i = 0; i < x; i++) if (ada[i] == 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
