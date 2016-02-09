#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int to[26];
int tmp[26];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  for(int i = 0; i < 26; i++) {
    to[i] = i;
  }
  while(m--) {
    char a, b;
    scanf(" %c %c", &a, &b);
    a -= 'a';
    b -= 'a';
    for(int i = 0; i < 26; i++) {
      tmp[i] = to[i];
    }
    for(int i = 0; i < 26; i++) {
      if(to[i] == a) {
        tmp[i] = b;
      }
    }
    for(int i = 0; i < 26; i++) {
      if(to[i] == b) {
        tmp[i] = a;
      }
    }
    for(int i = 0; i < 26; i++) {
      to[i] = tmp[i];
    }
  }
  for(int i = 0; i < n; i++) {
    s[i] = to[s[i] - 'a'] + 'a';
  }
  printf("%s\n", s);
  return 0;
}
