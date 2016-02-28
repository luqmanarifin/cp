#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<string> a, b;
char s[N];

bool is(string c) {
  int n = c.length();
  if(n == 0) return 0;
  for(int i = 0; i < n; i++) {
    if(c[i] == '.') return 0;
  }
  if(c[0] == '0' && n == 1) return 1;
  if(c[0] == '0') return 0;
  for(int i = 0; i < n; i++) {
    if(!('0' <= c[i] && c[i] <= '9')) {
      return 0;
    }
  }
  return 1;
}

void print(vector<string> c) {
  if(c.empty()) {
    puts("-");
    return;
  }
  printf("\"");
  for(int i = 0; i < c.size(); i++) {
    if(i) printf(",");
    printf("%s", c[i].c_str());
  }
  printf("\"\n");
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  vector<int> p;
  p.push_back(-1);
  for(int i = 0; i < n; i++) {
    if(s[i] == ',' || s[i] == ';') {
      p.push_back(i);
    }
  }
  for(int i = 0; i < p.size(); i++) {
    int til = n;
    if(i + 1 < p.size()) {
      til = min(til, p[i + 1]);
    }
    string str;
    for(int j = p[i] + 1; j < til; j++) {
      str.push_back(s[j]);
    }
    if(is(str)) {
      a.push_back(str);
    } else {
      b.push_back(str);
    }
  }
  print(a);
  print(b);
  return 0;
}
