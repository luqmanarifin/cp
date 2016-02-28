#include <bits/stdc++.h>

using namespace std;

class CartInSupermarketEasy {
public:
  int calc(int n, int k) {
    if(n == 1) return 1;
    if(memo[n][k]) return memo[n][k];
    int ret = calc(n - 1, k);
    for(int i = 1; i <= n / 2; i++) {
      for(int j = 0; j < k; j++) {
        int cur = max(calc(i, j), calc(n - i, k - j - 1));
        if(cur < ret) {
          ret = cur;
          //printf("%d ada %d pecah %d-%d dan %d-%d\n", n, k, i, j, n - i, k - j - 1);
        }
      }
    }
    return memo[n][k] = ret + 1;
  }
  int memo[105][105];
};
/*
int main() {
  CartInSupermarketEasy c;
  cout << c.calc(15, 4) << endl;
} */