#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> all;

int main() {
  srand(time(0));
  int t = 1000;
  int n = 6;
  printf("%d\n", t);
  while (t--) {
    int s = rand() % 201;
    int k = rand() % 2001;
    printf("%d %d %d\n", n, s, k);
  }

  return 0;
}
