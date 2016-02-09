#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool dua[N];
bool tiga[N];
bool delapan[N];
char s[N];
int f[N];

bool digit(char c) {
  return '0' <= c && c <= '9';
}

bool alpha(char c) {
  return 'A' <= c && c <= 'Z';
}

void build(int til, bool* nah, int len) {
  int l = 0, r = 0;
  while(l < len && r < len) {
    while(r < l + til && r < len && digit(s[r])) {
      r++;
    }
    if(l + til == r) {
      nah[l] = 1;
      l++;
    } else {
      l = ++r;
    }
  }
}

int main() {
  set<string> ans;
  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%s", s);
    string str = (string) s;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
      dua[i] = tiga[i] = delapan[i] = 0;
      f[i] = 1e8;
    }
    build(2, dua, len);
    build(3, tiga, len);
    build(8, delapan, len);
    for(int i = len - 2; i >= 0; i--) {
      f[i] = f[i + 1];
      if(alpha(s[i + 1])) {
        f[i] = i + 1;
      }
    }
    for(int i = 19; i < len;) {
      if(alpha(s[i]) && s[i - 1] == '-' && delapan[i - 9]
      && s[i - 10] == '-' && dua[i - 12] && s[i - 13] == '-'
      && dua[i - 15] && s[i - 16] == '-' && tiga[i - 19]) {
        ans.insert(str.substr(i - 19, 20));
      }
      i = f[i];
    }
    /*
    printf("DUA\n");
    for(int i = 0; i < len; i++) {
      printf("%d", dua[i]);
    }
    printf("\n");
    
    printf("TIGA\n");
    for(int i = 0; i < len; i++) {
      printf("%d", tiga[i]);
    }
    printf("\n");
    
    printf("DELAPAN\n");
    for(int i = 0; i < len; i++) {
      printf("%d", delapan[i]);
    }
    printf("\n");
    */
  }
  for(auto it : ans) {
    printf("%s\n", it.c_str());
  }
  if(ans.empty()) {
    puts("JUNK");
  }
  return 0;
}
