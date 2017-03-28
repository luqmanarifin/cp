#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], n;
bool dead[N];

int add(int now, int val) {
  for (int i = 0; i < val; i++) {
    now = (now + 1) % n;
    while (dead[now]) now = (now + 1) % n;
  }
  dead[now] = 1;
  return now;
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) scanf("%d", a + i);
  int now = 0;
  int len = n;
  for (int i = 0; i < k; i++) {
    a[i] %= len;
    now = add(now, a[i]);
    printf("%d ", now + 1);
    now = (now + 1) % n;
    while (dead[now]) now = (now + 1) % n;
    len--;
  }

  return 0;
}
