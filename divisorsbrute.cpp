#include <bits/stdc++.h>

using namespace std;

const int lim = 1e7;

bitset<lim + 5> is;
vector<long long> small;

vector<long long> factorize(long long num) {
  vector<long long> factor;
  for(long long prime : small) {
    if(num % prime == 0) {
      factor.push_back(prime);
    }
    while(num % prime == 0) {
      num /= prime;
    }
  }
  if(num != 1) factor.push_back(num);
  return factor;
}

int main() {
  for(int i = 2; 1LL * i * i < lim; i++) {
    if(!is[i]) {
      small.push_back(i);
      for(long long j = 1LL * i * i; j < lim; j += i) {
        is[j] = 1;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b;
    cin >> a >> b;
    if(b <= lim) {
    
      vector<long long> factor = factorize(b);
      bool can = 1;
      for(auto it : factor) {
        if(a % it) {
          can = 0;
          break;
        }
      }
      puts(can? "Yes" : "No");
    
    } else if(a <= lim) {
      
      vector<long long> factor = factorize(a);
      for(auto it : factor) {
        while(b % it == 0) b /= it;
      }
      puts(b == 1? "Yes" : "No");
    }
  }
  return 0;
}
