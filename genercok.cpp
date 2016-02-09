#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> count_time[N];
string prefix;

int hash_time(string& str) {
  int ret = 0;
  for(int i = 0; i < str.length(); i++) {
    ret = ret * 11 + str[i] - '0' + 1;
  }
  return ret;
}

int day[] = {
  0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool is_kabisat(int a) {
  if(a % 4 != 0) return 0;
  if(a % 100 != 0) return 1;
  if(a % 400 != 0) return 0;
  return 1;
}

long long to_int(string& a) {
  long long ret = 0;
  for(int i = 0; i < a.length(); i++) {
    ret = ret * 11 + a[i] - '0' + 1;
  }
  return ret;
}

string to_str(long long a) {
  stringstream ss;
  ss << a;
  return ss.str();
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
  return to_str(a);
}

string hh(int a) {
  if(a > 12) a -= 12;
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
  
}

string H(int a) {
  return to_str(a);
}

string HH(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

string yy(int a) {
  a = a % 100;
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

string yyyy(int a) {
  return to_str(a);
}

string mm(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

string ss(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

string M(int a) {
  return to_str(a);
}

string MM(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

string d(int a) {
  return to_str(a);
}

string dd(int a) {
  string tmp;
  if(a < 10) tmp = "0";
  return tmp + to_str(a);
}

bool is_palindrome(string str) {
  int len = str.length();
  for(int i = 0; i < len; i++) {
    if(str[i] != str[len - i - 1]) return 0;
  }
  return 1;
}

// termasuk validasi ada di precompute
// mengembalikan versi full dari string
vector<int> get_answer(string s, int cnt) {
  for(int i = 0; i < cnt; i++) {
    s.push_back('*');
  }
  int len = s.length();
  for(int i = 0; i < len; i++) {
    if(s[i] == '*' && s[len - i - 1] != '*') {
      s[i] = s[len - i - 1];
    }
  }
  if(('5' < s[len - 2] && s[len - 2] <= '9') || ('5' < s[len - 4] && s[len - 4] <= '9')) {
    return vector<int>();
  }
  vector<int> at;
  for(int i = 0; i < len; i++) {
    if(s[i] == '*') at.push_back(i);
  }
  vector<int> ret;
  //cout << at.size() << endl;
  if(at.size() == 0) {
    if(!is_palindrome(s)) {
      return vector<int>();
    }
    string suf = s.substr(len - cnt);
    ret.push_back(hash_time(suf));
    //cout << prefix << suf << endl;
    return ret;
  }
  if(at.size() == 1) {
    for(char i = '0'; i <= '9'; i++) {
      s[at[0]] = i;
      if(!is_palindrome(s)) {
        continue;
      }
      string suf = s.substr(len - cnt);
      ret.push_back(hash_time(suf));
      //cout << prefix << suf << endl;
    }
    return ret;
  }
  if(at.size() == 2) {
    for(char i = '0'; i <= '9'; i++) {
      s[at[0]] = i;
      for(char j = '0'; j <= '9'; j++) {
        s[at[1]] = j;
        if(!is_palindrome(s)) {
          continue;
        }
        string suf = s.substr(len - cnt);
        ret.push_back(hash_time(suf));
        //cout << prefix << suf << endl;
      }
    }
    return ret;
  }
  assert(false);
}

int solve(int year) {
  init(year);
  set<long long> done;
  int ans = 0;
  
  for(int mon = 1; mon <= 12; mon++) {
    for(int date = 1; date <= day[mon]; date++) {
      set<int> moments;
      for(int mask = 0; mask < (1 << 3); mask++) {
        string tmp;
        if(mask & 1) {
          tmp += M(mon);
        } else {
          tmp += MM(mon);
        }
        if(mask & 2) {
          tmp += d(date);
        } else {
          tmp += dd(date);
        }
        if(mask & 4) {
          tmp += yy(year);
        } else {
          tmp += yyyy(year);
        }
        //cout << tmp << endl;
        prefix = tmp;
        vector<int> a = get_answer(tmp, 5);
        //puts("JANCOK");
        for(auto it : a) {
          if(it >= N) continue;
          for(auto moment : count_time[it]) {
            moments.insert(moment);
          }
        }
        a = get_answer(tmp, 6);
        //puts("JANCOK 2");
        for(auto it : a) {
          if(it >= N) continue;
          //cout << it << endl;
          for(auto moment : count_time[it]) {
            moments.insert(moment);
          }
        }
        
        tmp = "";
        if(mask & 1) {
          tmp += d(date);
        } else {
          tmp += dd(date);
        }
        if(mask & 2) {
          tmp += M(mon);
        } else {
          tmp += MM(mon);
        }
        if(mask & 4) {
          tmp += yy(year);
        } else {
          tmp += yyyy(year);
        }
        //cout << tmp << endl;
        prefix = tmp;
        a = get_answer(tmp, 5);
        //puts("JANCOK 3");
        for(auto it : a) {
          if(it >= N) continue;
          for(auto moment : count_time[it]) {
            moments.insert(moment);
          }
        }
        a = get_answer(tmp, 6);
        //puts("JANCOK 4");
        for(auto it : a) {
          if(it >= N) continue;
          for(auto moment : count_time[it]) {
            moments.insert(moment);
          }
        }
      }
      ans += moments.size();
      /*
      for(auto it : moments) {
        printf("%d %d %d\n", it / 3600, (it % 3600) / 60, it % 60);
      }
      */
    }
  }
  return ans;
}

int main() {
  for(int i = 0; i < 60; i++) {
    for(int j = 0; j < 60; j++) {
      for(int k = 0; k < 24; k++) {
        string tmp;
        int hret;
        int cuk = k * 3600 + j * 60 + i;
        
        tmp = h(k) + mm(j) + ss(i);
        hret = hash_time(tmp);
        count_time[hret].push_back(cuk);
        
        tmp = hh(k) + mm(j) + ss(i);
        hret = hash_time(tmp);
        count_time[hret].push_back(cuk);
        
        tmp = H(k) + mm(j) + ss(i);
        hret = hash_time(tmp);
        count_time[hret].push_back(cuk);
        
        tmp = HH(k) + mm(j) + ss(i);
        hret = hash_time(tmp);
        count_time[hret].push_back(cuk);
      }
    }
  }
  for(int i = 0; i < N; i++) {
    sort(count_time[i].begin(), count_time[i].end());
    count_time[i].resize(distance(count_time[i].begin(), unique(count_time[i].begin(), count_time[i].end())));
    for(auto it : count_time[i]) {
      printf("{%d,%d},", i, it);
    }
  }
  return 0;
}
