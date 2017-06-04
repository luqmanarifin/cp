#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];

void update(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int main() {


  return 0;
}
