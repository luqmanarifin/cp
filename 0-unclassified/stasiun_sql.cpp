#include <bits/stdc++.h>

using namespace std;

char rom[] = {'I', 'V', 'X'};

bool iscode(string str) {
  int n = str.length();
  if(n != 3 && n != 2) {
    return 0;
  }
  for(int i = 0; i < n; i++) {
    int c = str[i] - 'A';
    if(!(0 <= c && c < 26)) {
      return 0;
    }
  }
  bool notrom = 0;
  for(int i = 0; i < n; i++) {
    bool bukan = 1;
    for(int j = 0; j < 3; j++) {
      if(rom[j] == str[i]) {
        bukan = 0;
      }
    }
    if(bukan) notrom = 1;
  }
  return notrom;
}

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  string buffer;
  while(getline(cin, buffer)) {
    stringstream ss(buffer);
    string kota, code;
    ss >> kota;
    bool ada = 0;
    while(ss >> code) {
      if(iscode(code)) {
        ada = 1;
        break;
      }
    }
    if(ada) {
      cout << "(\"" << code << "\", \"" << get(1, 6) << "\", \"" << get(1, 900) << "\", \"" << kota << "\"),"<< endl;
    }
  }
  
  return 0;
}
