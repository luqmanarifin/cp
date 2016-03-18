#include <bits/stdc++.h>

using namespace std;

deque<char> a, b;
char sa[5][5], sb[5][5];

void entry_a(char s) {
  if(s == 'X') return;
  a.push_back(s);
}

void entry_b(char s) {
  if(s == 'X') return;
  b.push_back(s);
}

int main() {
  scanf("%s %s %s %s", sa[0], sa[1], sb[0], sb[1]);
  entry_a(sa[0][0]);
  entry_a(sa[0][1]);
  entry_a(sa[1][1]);
  entry_a(sa[1][0]);
  
  entry_b(sb[0][0]);
  entry_b(sb[0][1]);
  entry_b(sb[1][1]);
  entry_b(sb[1][0]);
  while(a.front() != 'A') {
    char s = a.front();
    a.pop_front();
    a.push_back(s);
  }
  while(b.front() != 'A') {
    char s = b.front();
    b.pop_front();
    b.push_back(s);
  }
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
