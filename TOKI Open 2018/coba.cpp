#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

bool is[N];

int main() {
  for (int i = 1; i * i < N; i++) {
    is[i * i] = 1;
  }
  
  int ans = 0;
  for (int i = 1; i < 1000; i++) {
    for (int j = 1; j < 1000; j++) {
      if (is[i*i + j*j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
