#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];
vector<int> prime;

bool good(long long n) {
  for(auto it : prime) {
    if(n % (1LL * it * it) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
      prime.push_back(i);
    }
  }
  long long n;
  cin >> n;
  vector<long long> div;
  for(long long i = 1; 1LL * i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      if(n / i != i) {
        div.push_back(n / i);
      }
    }
  }
  sort(div.begin(), div.end());
  reverse(div.begin(), div.end());
  for(auto it : div) {
    if(good(it)) {
      cout << it << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
