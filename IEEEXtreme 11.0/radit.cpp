#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  printf("%d\n",(int)s.size() * 2 - 1);
  for(int i = 0;i < s.size(); ++i){
    for(int j = 0;j <=i; ++j){printf("%c", s[j]);}
    puts("");
  }
  for(int i = 1; i < s.size(); ++i){
    for(int j = i;j < s.size(); ++j) printf("%c", s[j]);
    puts("");
  }
  return 0;
}