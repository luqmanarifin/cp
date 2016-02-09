#include <bits/stdc++.h>

using namespace std;

string cuk = "duck";

char s[105];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    int j = 0;
    for(int i = 0; i < n && j < cuk.length(); i++) {
      if(s[i] == cuk[j]) {
        j++;
      }
    }
    printf("Case #%d: ", tt);
    puts(j == cuk.length()? "YES" : "NO");
  }
  
  return 0;
}
