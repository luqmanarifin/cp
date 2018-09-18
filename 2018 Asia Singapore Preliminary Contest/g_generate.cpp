#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 5;

bitset<N> is, answer;
vector<int> prime;

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) prime.push_back (i);
    for (int j = 0; j < prime.size () && 1LL * i * prime[j] < N; ++j) {
      is[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
    if (i % 1000000 == 0) printf("sieve %d\n", i);
  }
  for (int i = 0; i < N; i++) {
    if (!answer[i]) {
      printf("%d, ", i);
      fflush(stdout);
      for (auto it : prime) {
        if (i + it - 1 < N) {
          answer[i + it - 1] = 1;
        } else {
          break;
        }
      }
    }
  }

  return 0;
}
