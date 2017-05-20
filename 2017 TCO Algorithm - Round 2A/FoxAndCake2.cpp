#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int a[N][N];

class FoxAndCake2 {
public:
  string isPossible(int l, int r) {
    if (l > r) swap(l, r);
    if (__gcd(l, r) != 1) return "Possible";
    if (l == 1) return "Impossible";
    if (l == 2) {
      if (r % 2 == 0) {
        return "Possible"; 
      } else {
        return "Impossible";
      }
    }
    if (l == 3) {
      if (r % 3 == 0) {
        return "Possible"; 
      } else {
        return "Impossible";
      }
    }
    if (l == 4) {
      if (r % 2 == 0) {
        return "Possible"; 
      } else {
        return "Impossible";
      }
    }
    if (l == 5) {
      if (r == 6) {
        return "Impossible";
      } else {
        return "Possible"; 
      }
    }
    if (l == 6) {
      if (__gcd(l, r) != 1) {
        return "Possible"; 
      } else {
        return "Impossible";
      }
    }
    return "Possible";
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  
  FoxAndCake2 FoxAndCake2;
  cout << FoxAndCake2.isPossible() << endl;
  
  return 0;
}
*/