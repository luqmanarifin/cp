#include <bits/stdc++.h>

using namespace std;

const int inf = 1e6 + 5;

int f;

int get(int num) {
  if(num < 0) return inf / f - (-num - 1) / f;
  return num / f + inf / f + 1;
}

int main() {
  int l, r;
  scanf("%d %d %d", &l, &r, &f);
  cout << max(0, get(r) - get(l - 1)) << endl;
  return 0;
}
