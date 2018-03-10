#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int need(int x) {
  int ret = 0;
  for (int i = x; i >= 1; i--) {
    int j = i, sum = i;
    while (j - 1 >= 1 && sum + j - 1 <= N) {
      sum += j - 1;
      j--;
    }
    i = j;
    ret += 2;
  }
  return ret;
}

int main() {
  cout << need(85) << endl;

  return 0;
}
