#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];
int suf[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  if (s[n - 1] == '?') s[n - 1] = ')';
  if (s[0] == '?') s[0] = '(';
  int up = 0, need_up = 0;
  for (int i = 1; i + 1 < n; i++) {
    if (s[i] == '(') {
      up++;
    } else if (s[i] == ')') {
      if (up > 0) {
        up--;
      } else {
        need_up++;
      }
    }
  }
  for (int i = 1; i + 1 < n; i++) {
    if (s[i] == '?' && need_up > 0) {
      s[i] = '(';
      need_up--;
    }
  }
  int down = 0, need_down = 0;
  for (int i = n - 2; i >= 1; i--) {
    if (s[i] == ')') {
      down++;
    } else if (s[i] == '(') {
      if (down > 0) {
        down--;
      } else {
        need_down++;
      }
    }
  }
  for (int i = n - 2; i >= 1; i--) {
    if (s[i] == '?' && need_down > 0) {
      s[i] = ')';
      need_down--;
    }
  }
  int st = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (st == 0) {
        s[i] = '(';
      } else {
        s[i] = ')';
      }
      st ^= 1;
    }
  }

  int now = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      now++;
    } else if (s[i] == ')') {
      now--;
    } else {
      assert(0);
    }
    if (i != n - 1) {
      if (now <= 0) {
        puts(":(");
        return 0;
      }
    } else {
      if (now != 0) {
        puts(":(");
        return 0;
      }
    }
  }
  printf("%s\n", s);
  return 0;
}
