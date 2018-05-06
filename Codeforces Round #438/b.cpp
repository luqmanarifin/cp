
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tot = 12 * 3600;
  int h, m, s, t1, t2;
  scanf("%d %d %d %d %d", &h, &m, &s, &t1, &t2);
  h %= 12;
  t1 %= 12;
  t2 %= 12;
  h = h * 3600 + m * 60 + s;
  m = (m * 60 + s) * 12;
  s =  s * 12 * 60;
  //printf("tot %d: %d %d %d\n", tot, h, m, s);
  t1 = t1 * 3600;
  t2 = t2 * 3600;
  //printf("t1 t2 %d %d\n", t1, t2);
  bool ada = 0;
  for (int i = t1; i != t2; i = (i + 1) % tot) {
    if (i == h || i == m || i == s) {
      ada = 1;
      break;
    }
  }
  if (!ada) {
    puts("YES");
    return 0;
  }
  ada = 0;
  for (int i = t2; i != t1; i = (i + 1) % tot) {
    if (i == h || i == m || i == s) {
      ada = 1;
      break;
    }
  }
  if (!ada) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}
