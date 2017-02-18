#include <bits/stdc++.h>

using namespace std;

const int N = 505;

bool done[N];
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  string str;
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    if (!done[c]) {
      str.push_back(s[i]);
    }
    done[c] = 1;
  }
  if (str[0] != 'a') {
    puts("NO");
    return 0;
  }
  for (int i = 1; i < str.size(); i++) {
    if (str[i - 1] + 1 != str[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
