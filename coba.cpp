#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int nim[N];

int main() {
  nim[1] = 1;
  for(int i = 2; i < N; i++) {
    set<int> s;
    s.insert(nim[i - 1]);
    s.insert(nim[i / 2] ^ nim[(i + 1) / 2]);
    for(int j = 0; j < 10; j++) {
      if(!s.count(j)) {
        nim[i] = j;
        break;
      }
    }
  }
  for(int i = 0; i < 100; i++) printf("%d : %d\n", i, nim[i]);
  return 0;
}