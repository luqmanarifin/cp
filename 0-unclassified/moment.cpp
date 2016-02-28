#include <bits/stdc++.h>

using namespace std;

vector<int> pre, prek;

int day[] = {
  0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

string convert(int a) {
  stringstream ss;
  int ret;
  ss << a;
  return ss.str();
}

bool is_kabisat(int a) {
  if(a % 4 != 0) return 0;
  if(a % 100 != 0) return 1;
  if(a % 400 != 0) return 0;
  return 1;
}

long long to_int(string a) {
  long long ret = 0;
  for(int i = 0; i < a.length(); i++) {
    ret = ret * 10 + a[i] - '0';
  }
  return ret;
}

void init(int a) {
  if(is_kabisat(a)) {
    day[2] = 29;
  } else {
    day[2] = 28;
  }
}

string h(int a) {
  if(a > 12) a -= 12;
  return convert(a);
}

string hh(int a) {
  if(a > 12) a -= 12;
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + convert(a);
  
}

string H(int a) {
  return convert(a);
}

string HH(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + convert(a);
}

string yy(int a) {
  a = a % 100;
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + convert(a);
}

string yyyy(int a) {
  return convert(a);
}

string mm(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + convert(a);
}

string ss(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + convert(a);
}

bool is_palindrome(string str) {
  int len = str.length();
  for(int i = 0; i < len; i++) {
    if(str[i] != str[len - i - 1]) return 0;
  }
  return 1;
}

string get_prefix(string a, int cnt) {
  string str = "";
  for(int i = 0; i < cnt; i++) {
    str.push_back('*');
  }
  str = str + a;
  int len = str.length();
  for(int i = 0; i < len; i++) {
    if(str[i] == '*') {
      str[i] = str[len - i - 1];
    }
  }
  if(is_palindrome(str) && str[0] != '0') {
    return str.substr(0, cnt);
  }
  return "";
}

#define entry for(int i = 2; i <= 4; i++) {\
                prefix = get_prefix(tmp, i);\
                long long hash_ret = to_int(prefix + tmp);\
                if(prefix.length() > 0) {\
                  if(binary_search(p.begin(), p.end(), (int) to_int(prefix))) {\
                    if(!done.count(hash_ret)) {\
                      cout << prefix + tmp << endl;\
                      ans++;\
                      done.insert(hash_ret);\
                    }\
                  }\
                }\
              }

int solve(vector<int>& p, int year) {
  set<long long> done;
  
  int ans = 0;
  for(int hou = 0; hou < 24; hou++) {
    for(int minu = 0; minu < 60; minu++) {
      for(int sec = 0; sec < 60; sec++) {
        //printf("%d %d %d\n", hou, minu, sec);
        string tmp, prefix;
        
        tmp = yy(year) + h(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yy(year) + hh(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yy(year) + H(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yy(year) + HH(hou) + mm(minu) + ss(sec);
        entry;
        
        // ganti model year
        
        tmp = yyyy(year) + h(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yyyy(year) + hh(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yyyy(year) + H(hou) + mm(minu) + ss(sec);
        entry;
        
        tmp = yyyy(year) + HH(hou) + mm(minu) + ss(sec);
        entry;
      }
    }
  }
  return ans;
}

int find(int year) {
  return solve(is_kabisat(year)? prek : pre, year);
}

int main() {
  init(4);
  for(int i = 1; i <= 12; i++) {
    for(int j = 1; j <= day[i]; j++) {
      string temp = convert(i) + convert(j);
      prek.push_back(to_int(temp));
    }
  }
  
  init(3);
  for(int i = 1; i <= 12; i++) {
    for(int j = 1; j <= day[i]; j++) {
      string temp = convert(i) + convert(j);
      pre.push_back(to_int(temp));
    }
  }
  sort(pre.begin(), pre.end());
  sort(prek.begin(), prek.end());
  pre.resize(distance(pre.begin(), unique(pre.begin(), pre.end())));
  prek.resize(distance(prek.begin(), unique(prek.begin(), prek.end())));
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", find(n));
  }
  
  return 0;
}
