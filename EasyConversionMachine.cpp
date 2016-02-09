#include <bits/stdc++.h>

using namespace std;

class EasyConversionMachine {
public:
  string isItPossible(string a, string b, int k) {
    int aa = a.length();
    int bb = b.length();
    if(aa != bb) return "IMPOSSIBLE";
    int temp = 0;
    for(int i = 0; i < aa; i++) {
      if(a[i] != b[i]) {
        temp++;
      }
    }
    return (temp % 2 == k % 2 && temp <= k? "POSSIBLE" : "IMPOSSIBLE");
  }
};