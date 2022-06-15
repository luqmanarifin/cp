#include <bits/stdc++.h>

using namespace std;

bool done[24][60];
char buf[10];

bool is(int u, int v) {
  int a = u / 10;
  int b = u % 10;
  int c = v / 10;
  int d = v % 10;
  return a == d && b == c;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));

    int u, v, c;
    scanf("%s %d", buf, &c);
    u = (buf[0] - '0') * 10 + buf[1] - '0';
    v = (buf[3] - '0') * 10 + buf[4] - '0';

    int cnt = 0;
    while (!done[u][v]) {
      done[u][v] = 1;
      if (is(u, v)) cnt++;
      v += c;

      u += v / 60;
      v %= 60;
      u %= 24;
    }
    printf("%d\n", cnt);
  }

  return 0;
}
