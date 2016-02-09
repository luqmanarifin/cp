// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
char a[] = "<{[(";
char b[] = ">}])";

int at(char c) {
  for(int i = 0; i < 4; i++) {
    if(a[i] == c || b[i] == c) return i;
  }
  assert(false);
}

int val(char c) {
  for(int i = 0; i < 4; i++) {
    if(a[i] == c) return 1;
  }
  return -1;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int mini = 0, now = 0;
  for(int i = 0; i < n; i++) {
    now += val(s[i]);
    mini = min(mini, now);
  }
  if(now != 0 || mini < 0) {
    puts("Impossible");
    return 0;
  }
  stack<char> st;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(val(s[i]) == 1) {
      st.push(s[i]);
    } else {
      char top = st.top();
      st.pop();
      ans += at(top) != at(s[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
