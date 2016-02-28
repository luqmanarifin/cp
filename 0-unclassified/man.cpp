#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
  getline(cin, str);
  for(auto it : str) {
    cout << it;
    if(it == ';') cout << endl;
  }
  
  return 0;
}
