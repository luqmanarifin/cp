#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int nim[N], is[N];
vector<int> p;

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for (int i = 1; i < 1005; i++) {
    set<int> s;
    for (auto it : p) {
      if (i >= it - 1) {
        s.insert(nim[i - (it - 1)]);
      }
    }
    for (int j = 0; ; j++) {
      if (!s.count(j)) {
        nim[i] = j;
        break;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    printf("%d: %d\n", i, nim[i]);
  }
  return 0;
}
