#include <bits/stdc++.h>

using namespace std;

char s[55];
string str;
int n;

// -1 if fail
int getnum(int p) {
  int num = 0;
  while(p < n && '0' <= s[p] && s[p] <= '9' && num <= 50) {
    num = num * 10 + s[p] - '0';
    p++;
  }
  if(num > 50) return -1;
  while(num--) str.push_back(s[p]);
  return p;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0; i < n; i++) {
    if('A' <= s[i] && s[i] <= 'Z') {
      str.push_back(s[i]);
    } else {
      i = getnum(i);
      if(i == -1) {
        puts("TOO LONG");
        return 0;
      }
    }
  }
  if(str.length() <= 50) {
    cout << str << endl;
  } else {
    puts("TOO LONG");
  }
  return 0;
}
