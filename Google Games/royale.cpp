#include <bits/stdc++.h>

using namespace std;

const int N = 52;

bool check(int i, int j, int k, int l, int m) {
  int sum = i % 13 + j % 13 + k % 13 + 
}

int main() {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          for (int m = l + 1; m < N; m++) {
            if (cek(i, j, k, l, m)) {
              ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
