#include <bits/stdc++.h>

using namespace std;

class EllysSki {
public:
  int getMax(vector<int> a) {
    int ret = 1;
    int n = a.size();
    int now = 1;
    for (int i = 1; i < n; i++) {
      if (a[i-1] < a[i]) {
        now = 1;
      } else {
        now++;
      }
      ret = max(ret, now);
    }
    now = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i+1]) {
        now = 1;
      } else {
        now++;
      }
      ret = max(ret, now);
    }
    return ret;
  }
};

// int main() {
//   int l = 0;
//   int r = 0;

//   EllysSki EllysSki;
//   cout << EllysSki.getMax() << endl;

//   return 0;
// }
