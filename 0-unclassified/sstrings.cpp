#include <bits/stdc++.h>

using namespace std;

vector<int> awal;
char s[105];
bool done[26];

int main() {
  int q;
  scanf("%d", &q);
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    s[i] -= 'a';
    if(!done[s[i]]) {
      awal.push_back(i);
      done[s[i]] = 1;
    }
  }
  if(awal.size() < q) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for(int i = 0; i + 1 < q; i++) {
    for(int j = awal[i]; j < awal[i + 1]; j++) {
      printf("%c", s[j] + 'a');
    }
    printf("\n");
  }
  for(int i = awal[q - 1]; i < n; i++) {
    printf("%c", s[i] + 'a');
  }  
  return 0;
}
