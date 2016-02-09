#include <bits/stdc++.h>

using namespace std;

vector<string> code;

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  string buffer;
  while(getline(cin, buffer)) {
    code.push_back(buffer);
  }
  
  //cout << "INSERT INTO `bekerja` (`ID_Pegawai`, `No_Kereta`)" << endl;
  //cout << "VALUES" << endl << endl;
  int id = 1100;
  for(int i = 114; i <= 225; i++) {
    for(int j = 0; j < 5; j++) {
      id++;
      //cout << "(\"" << ++id << "\", \"" << i << "\")";
      //if(i == 225 && j == 4) cout << ";" << endl;
      //else cout << "," << endl;
    }
  }
  
  cout << "INSERT INTO `bekerja` (`ID_Pegawai`, `ID_Stasiun`)" << endl;
  cout << "VALUES" << endl << endl;
  for(; id < 3800;) {
    cout << "(\"" << ++id << "\", \"" << code[get(0, code.size() - 1)] << "\")";
    if(id == 3800) cout << ";" << endl;
    else cout << "," << endl;
  }
  
  return 0;
}
