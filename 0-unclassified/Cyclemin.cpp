#include <bits/stdc++.h>

using namespace std;

class Cyclemin {
public:
  string bestmod(string s, int k) {
    string best = s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
      int temp = s[0];
      for(int j = 0; j < n - 1; j++) {
        s[j] = s[j + 1];
      }
      s[n - 1] = temp;
      string t = s;
      int code = k;
      for(int j = 0; j < n && code; j++) {
        if(t[j] == 'a') continue;
        t[j] = 'a';
        code--;
      }
      best = min(best, t);
    }
    return best;
  }
};
/*
int main() {
  string s = "abacaba";
  int k = 1;
  Cyclemin c;
  cout << c.bestmod(s, k) << endl;
  
  return 0;
}
*/

