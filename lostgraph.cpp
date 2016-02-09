#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
  int n;
  cin >> n;
  int m = 2 * n;
  while(m--) {
    string str; int a;
    cin >> str >> a;
    if(str == "in") {
      if(!st.empty()) {
        printf("%d %d\n", a, st.top());
      }
      st.push(a);
    } else {
      st.pop();
    }
  }
  
  return 0;
}
