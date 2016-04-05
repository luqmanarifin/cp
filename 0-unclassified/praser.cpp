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

string str;

int main() {
  int num = 0;
  int last = -1;
  while(getline(cin, str)) {
    int id = atoi(str.c_str());
    if(id != 0) {
      vector<string> s = parse(str), now;
      for(int i = 1; i < s.size(); i++) {
        now.push_back(s[i]);
      }
      // insert kecamatan here
      printf("INSERT INTO kecamatan (id, nama, alamat_kantor, id_pengurus, id_kota, created_at, updated_at, status) VALUES (\'%d\', \'%s\', \'Jalan Ganesha 10 Bandung\', \'1\', \'0\', CURRENT_TIMESTAMP, NULL,1);\n", id, combine(now).c_str()); 
      last = id;
      
    } else {
      string kel = str;
      // insert kelurahan here
      ++num;
      printf("INSERT INTO kelurahan (id, nama, alamat_kantor, id_pengurus, id_kecamatan, created_at, updated_at, status) VALUES (\'%d\', \'%s\', \'Jalan Ganesha 10 Bandung\', \'1\', \'%d\', CURRENT_TIMESTAMP, NULL,1);\n", num, kel.c_str(), last); 
      
    }
  }
  return 0;
}
