#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ned[26][2];
int ada[26][2];
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    if('a' <= s[i] && s[i] <= 'z') ned[s[i]-'a'][0]++;
    else ned[s[i]-'A'][1]++;
  }
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0; i < n; i++) {
    if('a' <= s[i] && s[i] <= 'z') ada[s[i]-'a'][0]++;
    else ada[s[i]-'A'][1]++;
  }
  int yay = 0, whop = 0;
  for(int i = 0; i < 26; i++) {
    int sm = min(ada[i][0], ned[i][0]);
    int bg = min(ada[i][1], ned[i][1]);
    yay += sm + bg;
    ada[i][0] -= sm;
    ada[i][1] -= bg;
    ned[i][0] -= sm;
    ned[i][1] -= bg;
    sm = min(ada[i][0], ned[i][1]);
    bg = min(ada[i][1], ned[i][0]);
    whop += sm + bg;
    ada[i][0] -= sm;
    ada[i][1] -= bg;
  }
  printf("%d %d\n", yay, whop);
  return 0;
}