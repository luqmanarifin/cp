#include <bits/stdc++.h>

using namespace std;

char s[500];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int now = 0;
  int maxi = 0, mini = 0;
  for(int i = 0; i < n; i++) {
    now = now + (s[i] == '+'? 1 : -1);
    maxi = max(maxi, now);
    mini = min(mini, now);
  }
  cout << maxi - mini << endl;
  return 0;
}