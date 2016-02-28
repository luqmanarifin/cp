#include <bits/stdc++.h>

using namespace std;

string str[] = {"rat", "woman", "child", "man", "captain"};

string s[105];
int t[105];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string temp;
    cin >> s[i] >> temp;
    for(int j = 0; j < 5; j++) {
      if(temp == str[j]) {
        t[i] = j;
      }
    }
    if(t[i] >= 2) t[i]--;
  }
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < n; i++) {
      if(t[i] == j) {
        cout << s[i] << endl;
      }
    }
  }
  
  return 0;
}
