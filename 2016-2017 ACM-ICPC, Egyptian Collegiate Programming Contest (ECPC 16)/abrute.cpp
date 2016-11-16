#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int nim[N];

int main() {
  for (int b = 1; b <= 10; b++) {
    for (int i = 1; i < N; i++) {
      set<int> s;
      for (int j = 1; j <= i; j *= b) {
        //printf("%d %d %d\n", b, i, j);
        s.insert(nim[i - j]);
        if (b == 1) break;
      }
      for (int j = 0; j < N; j++) {
        if (!s.count(j)) {
          nim[i] = j;
          break;
        }
      }
    }
    for (int i = 0; i < N; i++) printf("%d ", nim[i]); printf("\n");
  }
  

  return 0;
}
