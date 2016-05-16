#include <bits/stdc++.h>

using namespace std;

string com, who;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int sum = 0, n, val;
    cin >> n >> who;
    while(n--) {
      cin >> com;
      if(com == "CONTEST_WON") {
        cin >> val;
        if(val <= 20) {
          sum += 320 - val;
        } else if(val <= 500) {
          sum += 300;
        }
      } else if(com == "TOP_CONTRIBUTOR") {
        sum += 300;
      } else if(com == "BUG_FOUND") {
        cin >> val;
        sum += val;
      } else {
        sum += 50;
      }
    }
    int ans;
    if(who == "INDIAN") {
      ans = sum / 200;
    } else {
      ans = sum / 400;
    }
    cout << ans << endl;
  }
  
  return 0;
}