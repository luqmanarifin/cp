#include <bits/stdc++.h>

using namespace std;

const int BIG = 2e5 + 5;

int day[BIG];

int main() {
  int n;
  scanf("%d", &n);
  int longest = -1;
  while (n--) {
    int h, r, t;
    scanf("%d %d %d", &h, &r, &t);
    longest = max(longest, h);
    for (int i = 0; h * i < BIG; i++) {
      if (r < t) {
        for (int j = r + 1; j < t; j++) {
          if (i * h + j < BIG) {
            day[i * h + j] = 1;
          }
        }
      } else {
        for (int j = r + 1; j < h; j++) {
          if (i * h + j < BIG) {
            day[i * h + j] = 1;
          }
        }
        for (int j = 0; j < t; j++) {
          if (i * h + j < BIG) {
            day[i * h + j] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < longest * 1825; i++) {
    if (day[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  puts("impossible");
  return 0;
}
