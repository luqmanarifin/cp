#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N];

int main() {
  int n = 20;
  while (cin >> s) {
    bool done = 0;
    int sa = 0, sb = 0, ka = 5, kb = 5;
    for (int i = 0; i < 10; i += 2) {
      if (s[i] == '1') sa++;
      ka--;
      if (sa > sb + kb) {
        printf("TEAM-A %d\n", i + 1);
        done = 1;
        break;
      }
      if (sb > sa + ka) {
        printf("TEAM-B %d\n", i + 1);
        done = 1;
        break;
      }
      
      if (s[i + 1] == '1') sb++;
      kb--;
      if (sa > sb + kb) {
        printf("TEAM-A %d\n", i + 2);
        done = 1;
        break;
      }
      if (sb > sa + ka) {
        printf("TEAM-B %d\n", i + 2);
        done = 1;
        break;
      }
    }
    if (done) continue;
    for (int i = 10; i < n; i += 2) {
      if (s[i] == '1') sa++;
      if (s[i + 1] == '1') sb++;
      if (sa > sb + kb) {
        printf("TEAM-A %d\n", i + 2);
        done = 1;
        break;
      }
      if (sb > sa + ka) {
        printf("TEAM-B %d\n", i + 2);
        done = 1;
        break;
      }
    }
    if (!done) puts("TIE");
  }

  return 0;
}
