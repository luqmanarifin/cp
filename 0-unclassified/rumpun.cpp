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
  while(getline(cin, buffer)) {
    vector<string> v = parse(buffer);
    vector<string> ret;
    if(v.size() == 0) continue;
    for(int i = 1; i < v.size(); i++) {
      if(v[i] == "Rumpun" && i != 1) break;
      ret.push_back(v[i]);
    }
    int id = atoi(v[0].c_str());
    if(id == 0) continue;
    string name = combine(ret);
    //cerr << v.size() << endl;
    //printf("%d %s\n", id, name.c_str());
    printf("INSERT INTO rumpun (id, nama, nomor_urut, created_at, updated_at, status) VALUES (\'%d\', \'%s\', \'%d\', CURRENT_TIMESTAMP, NULL, 1);\n", id, name.c_str(), id); 
  }
  
  return 0;
}
