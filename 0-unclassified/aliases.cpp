#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

vector<string> ans[N];
map<string, int> mp;
set<string> ada;
string buf;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int id = 0;
  for(int i = 0; i < n; i++) {
    cin >> buf;
    string asli = buf;
    transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
    string domain;
    bool a = 0;
    for(int i = 0; i < buf.size(); i++) {
      if(a) {
        domain.push_back(buf[i]);
      }
      if(buf[i] == '@') {
        a = 1;
      }
    }
    bool ok = domain == "bmail.com";
    
    string s;
    bool ap = 0, ba = 1;
    for(int i = 0; i < buf.size(); i++) {
      if(buf[i] == '+') {
        ap = 1;
        if(!ok) {
          s.push_back(buf[i]);
        }
      } else if(buf[i] == '@') {
        ba = 0;
        s.push_back(buf[i]);
      } else {
        if(ap && ba && ok) {
          continue;
        }
        if(buf[i] == '.' && ba && ok) {
          continue;
        }
        s.push_back(buf[i]);
      }
    }
    if(!ada.count(s)) {
      mp[s] = id++;
      ada.insert(s);
    }
    ans[mp[s]].push_back(asli);
  }
  printf("%d\n", id);
  for(int i = 0; i < id; i++) {
    printf("%d ", ans[i].size());
    for(auto it : ans[i]) {
      printf("%s ", it.c_str());
    }
    printf("\n");
  }
  return 0;
}
