#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

vector<long long> x;

int main() {
  for (long long i = 1; i < N; i++) {
    x.push_back(i * i);
  }
  int cute = 0, non_cute = 0;
  for (int i = 1; i < N; i++) {
    int f = x[int(upper_bound(x.begin(), x.end(), i) - x.begin())];
    int g = x[int(upper_bound(x.begin(), x.end(), i) - x.begin() - 1)];
    if (i - g < f - i) {
      cute++;
    } else {
      non_cute++;
    }
  }
  printf("%d %d\n", cute, non_cute);
  return 0;
}
