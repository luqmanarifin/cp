
#include <bits/stdc++.h>

using namespace std;

int h1, a1, c1, h2, a2;
int attacks;

bool can(int heal) {
  attacks = 0;
  int hku = h1, hmu = h2;
  for (int i = 0; i < heal; i++) {
    hku += c1;
    hku -= a2;
  }
  while (1) {
    attacks++;
    hmu -= a1;
    if (hmu <= 0) return 1;
    hku -= a2;
    if (hku <= 0) return 0;
  }
  assert(0);
}

int main() {
  scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
  int l = 0, r = 1000000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  can(l);
  printf("%d\n", l + attacks);
  for (int i = 0; i < l; i++) puts("HEAL");
  for (int i = 0; i < attacks; i++) puts("STRIKE");
  return 0;
}
