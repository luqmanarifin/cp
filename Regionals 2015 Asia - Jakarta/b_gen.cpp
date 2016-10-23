#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int nim[N];

int main() {
  nim[1] = nim[2] = 1;
  nim[3] = 2;
  int bef = -1;
  for (int i = 4; i < N; i++) {
    set<int> s;
    for (int j = 1; j + 1 < i; j++) {
      int now = 0;
      if (j > 1) now ^= nim[j - 1];
      if (j < i - 2) now ^= nim[i - j - 2];
      s.insert(now);
    }
    s.insert(nim[i - 2]);
    for (int j = 0; j < 2 * N; j++) {
      if (!s.count(j)) {
        nim[i] = j;
        break;
      }
    }
    if (nim[i] == 0) {
      printf(", %d", i );
      bef = i;
    }
  }
  return 0;
}
