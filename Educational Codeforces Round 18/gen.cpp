#include <bits/stdc++.h>
#include <random>

using namespace std;

int main() {
      std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(1,1e9); // guaranteed unbiased
  int n = 500;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {

    auto random_integer = uni(rng);
    printf("%d ", random_integer);
  }
  return 0;
}
