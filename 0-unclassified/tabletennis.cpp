#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') cnt1++;
      else cnt0++;
    }
    puts(cnt1 > cnt0? "WIN" : "LOSE");
  }
  
  return 0;
}
