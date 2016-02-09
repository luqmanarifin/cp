#include <bits/stdc++.h>

using namespace std;

char s[10][10];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < 9; i++) {
      scanf("%s", s[i]);
    }
    bool valid = 1;
    for(int i = 0; i < 9; i++) {
      vector<int> p;
      for(int j = 0; j < 9; j++) {
        p.push_back(s[i][j]);
      }
      sort(p.begin(), p.end());
      for(int j = 1; j < p.size(); j++) {
        if(p[j] == p[j - 1]) {
          valid = 0;
          break;
        }
      }
    }
    for(int j = 0; j < 9; j++) {
      vector<int> p;
      for(int i = 0; i < 9; i++) {
        p.push_back(s[i][j]);
      }
      sort(p.begin(), p.end());
      for(int i = 1; i < p.size(); i++) {
        if(p[i] == p[i - 1]) {
          valid = 0;
          break;
        }
      }
    }
    for(int i = 0; i < 9; i++) {
      int ta = i / 3 * 3;
      int tb = i % 3 * 3;
      vector<int> p;
      for(int j = 0; j < 9; j++) {
        p.push_back(s[ta + j / 3][tb + j % 3]);
      }
      sort(p.begin(), p.end());
      for(int j = 1; j < p.size(); j++) {
        if(p[j] == p[j - 1]) {
          valid = 0;
          break;
        }
      }
    }
    puts(valid? "Valid" : "Invalid");
  }
  
  return 0;
}
