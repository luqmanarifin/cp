#include <bits/stdc++.h>

using namespace std;

const string NAME = "alignment";

const int N = 180;
vector<vector<string> > v;

vector<string> split_str(const string& s){
  stringstream ss(s);
  vector<string> ans;
  string buf;
  while(ss >> buf){
    ans.push_back(buf);
  }
  return ans;  
}

int mins[N + 5];

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  string s;
  while(getline(cin, s)){
    v.push_back(split_str(s));
  }
  fprintf(stderr, "SIZE : %d\n", (int)v.size());
  bool masih = true;
  int idx = 0;
  int maks = 0;
  while(masih){
    masih = false;    
    int maksnow = 0;
    for(int i = 0;i < (int) v.size(); ++i){
      if((int) v[i].size() <= idx) continue;
      masih = true;
      maksnow = max(maksnow, (int)v[i][idx].size());
    }    
    mins[idx] = maks;
    maks += maksnow + 1;
    idx++;
  }
  
  for(int i = 0;i < (int) v.size(); ++i){
    string s = "";
    int now = 0;
    for(int j = 0;j < (int)v[i].size(); ++j){
      for(int k = (int)s.length(); k < mins[j]; ++k) s += " ";
      s += v[i][j];
    }
    cout << s << endl;
  }
  
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

