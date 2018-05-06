
#include <bits/stdc++.h>

using namespace std;

int ok[256];
string str = "aiueoy";
char s[1005];

int main() {
  for (int i = 0; i < str.size(); i++) ok[str[i]] = 1;
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) {
    printf("%c", s[i]);
    while (i + 1 < n && ok[s[i]] && ok[s[i + 1]]) i++;
  }
  return 0;
}
