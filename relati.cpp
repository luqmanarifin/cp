#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    string op;
    cin >> a >> op >> b;
    if(op == "!=") puts(a != b? "true" : "false");
    else if(op == "==") puts(a == b? "true" : "false");
    else if(op == "<") puts(a < b? "true" : "false");
    else if(op == "<=") puts(a <= b? "true" : "false");
    else if(op == ">") puts(a > b? "true" : "false");
    else if(op == ">=") puts(a >= b? "true" : "false");
  }
  
  return 0;
}
