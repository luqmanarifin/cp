// Author: Ivan Katanic
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 1000100;
const int mod = 1e9 + 7;

int main(void) {
  static char a[MAX];
  int N, M;
  scanf("%d %d", &N, &M);
  scanf("%s", a);

  int h = 0, ans = 1;
  for (int i = 0; i < N; ++i) {
    h = (h * 10 + a[i]-'0') % M;
    if (h == 0 && i < N-1) ans = ans*2 % mod;
  }
  if (h) ans = 0;

  printf("%d\n", ans);
  return 0;
}
