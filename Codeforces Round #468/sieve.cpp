#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int last[N];  // biggest prime

int main() {
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      for (int j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  return 0;
}
