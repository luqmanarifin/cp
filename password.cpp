#include <bits/stdc++.h>

using namespace std;

string s[10];
char a[100];

int main() {
  cin >> a;
  for(int i = 0; i < 10; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < 8; i++) {
    string q = "";
    for(int j = 0; j < 10; j++) {
      q.push_back(a[i * 10 + j]);
    }
    for(int j = 0; j < 10; j++) {
      if(q == s[j]) {
        cout << j;
        break;
      }
    }
  }
  
  return 0;
}
