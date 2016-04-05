#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string s) {
  stringstream ss(s);
  string buf;
  vector<string> ret;
  int cnt = 0;
  while(ss >> buf) {
    ret.push_back(buf);
  }
  return ret;
}

string combine(vector<string> s) {
  string ret;
  for(auto it : s) {
    ret += it + " ";
  }
  return ret;
}

string buffer;

int main() {
  int id = 0;
  while(getline(cin, buffer)){
    ++id;
    int id_rumpun = rand() % 25 + 1;
    bool kual = rand() % 2;
    int nilai = rand() % 21 + 70;
    printf("INSERT INTO jabatan (id, id_rumpun, nama, kualifikasi, keterangan, kode, nilai, created_at, updated_at, status) VALUES (%d, %d, \'%s\', \'%s\', \'kentang\', \'IF%d\', %d, CURRENT_TIMESTAMP, NULL, 1);\n", id, id_rumpun, buffer.c_str(), (kual? "Pendidikan": "Keahlian"), id, nilai); 
  }
  return 0;
}
