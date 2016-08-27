#include <bits/stdc++.h>

using namespace std;

const int N = 1e9;
const int M = 1e5 + 5;

vector<int> prime;
bool is[M];

int main() {
  for (int i = 2; i < M; i++) {
    if (!is[i]) {
      cout << i << endl;
      prime.push_back(i);
      for (long long j = 1LL * i * i; j < M; j += i) {
        is[j] = 1;
      }
    }
  }  
  cout << prime.size() << endl;
  return 0;
}
