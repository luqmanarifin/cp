#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool first_r, first_b, first_y;
int n, r, o, y, g, b, v;

char s[N];
int player, same;

void draw(char c) {
  if (c == 'R' && first_r) {
    for (int i = 0; i < g; i++) printf("RG");
  }
  if (c == 'B' && first_b) {
    for (int i = 0; i < o; i++) printf("BO");
  }
  if (c == 'Y' && first_y) {
    for (int i = 0; i < v; i++) printf("YV");
  }
  if (!same) printf("%c", c);
  if (c == 'R') first_r = 0;
  if (c == 'B') first_b = 0;
  if (c == 'Y') first_y = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    first_b = first_r = first_y = 1;
    same = 0;
    
    scanf("%d %d %d %d %d %d %d", &n, &r, &o, &y, &g, &b, &v);
    printf("Case #%d: ", tt);
    player = (r || g) + (o || b) + (v || y);
    
    int R = 0, B = 0, Y = 0, tot = 0;
    if (player == 1) {
      if ((r && r != g) || (b && b != o) || (y && y != v)) {
        puts("IMPOSSIBLE");
        continue;
      }
      if (r) {
        for (int i = 0; i < g; i++) printf("RG");
        for (int i = 0; i < r - g; i++) printf("R");
      } else if (b) {
        for (int i = 0; i < o; i++) printf("BO");
        for (int i = 0; i < b - o; i++) printf("B");
      } else {
        for (int i = 0; i < v; i++) printf("YV");
        for (int i = 0; i < y - v; i++) printf("Y");
      }
      printf("\n");
      continue;
    } else {
      R = r - g;
      B = b - o;
      Y = y - v;
      tot = R + B + Y;
      int lim = (R + B + Y) / 2;
      if (R > lim || B > lim || Y > lim) {
        puts("IMPOSSIBLE");
        continue;
      }
      if ((g && r <= g) || (o && b <= o) || (v && y <= v)) {
        puts("IMPOSSIBLE");
        continue;
      }
    }

    memset(s, 0, sizeof(s));
    for (int i = 0, p = 0; i < R; i++, p += 2) s[p] = 'R';
    for (int i = 0, p = (tot/2*2)-1; i < B; i++, p -= 2) s[p] = 'B';
    for (int i = 0; i < tot; i++) if (s[i] == 0) s[i] = 'Y';
    for (int i = 0; i < tot; i++) if (s[i] == s[(i+1)%tot]) {
      swap(s[(i+1)%tot], s[(i+2)%tot]);
    }
    for (int i = 0; i < tot; i++) draw(s[i]);
    printf("\n");
  }

  return 0;
}
