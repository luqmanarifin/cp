#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];

int main() {
  is[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n;
  while (cin >> n) {
    if (is[n]) {
      puts("bukan prima");
    } else {
      puts("prima");
    }
  }

  return 0;
}
