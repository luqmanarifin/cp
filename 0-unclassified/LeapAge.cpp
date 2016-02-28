#include <bits/stdc++.h>

using namespace std;

class LeapAge {
public:
  bool leap(int a) {
    if(a % 100 == 0 && a % 400) return 0;
    if(a % 4 == 0) return 1;
    return 0;
  }
  int getAge(int y, int b) {
    int ans = 0;
    for(int i = b + 1; i <= y; i++) {
      if(leap(i)) {
        ans++;
      }
    }
    return ans;
  }
};
/*
int main() {
  int l = 0;
  int r = 0;
  
  LeapAge LeapAge;
  cout << LeapAge.getAge() << endl;
  
  return 0;
}
*/