#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 6;
  int half = n / 2;
  for(int k = 0; k < n; k++) {
    for(int at = 0; at < half; at++) {
      vector<int> bunyi, num;
      for(int i = 0; i < n; i++) {
        num.push_back(i);
      }
      for(int i = n - 1; i >= 0; i--) {
        num.push_back(i);
      }
      for(int i = 0; i < num.size(); i++) {
        if(num[i] == at && i + k < num.size()) {
          bunyi.push_back(num[i + k]);
        }
      }
      printf("%d %d: ", k, at);
      for(auto it : bunyi) printf("%d ", it); printf("\n");
    }
  }
  
  return 0;
}
