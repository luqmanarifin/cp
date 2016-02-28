#include <bits/stdc++.h>

using namespace std;

int main() {
  string buffer;
  int n = 4;
  while(n--) {
    getline(cin, buffer);
  }
  while(getline(cin, buffer)) {
    int i = 2;
    while(buffer[i] != '\"') {
      cout << buffer[i];
      i++;
    }
    cout << endl;
  }
  
  return 0;
}
