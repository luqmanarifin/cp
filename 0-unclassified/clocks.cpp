#include <bits/stdc++.h>

using namespace std;

int ping[] = {60 * 60* 1000, 60 * 1000, 1000, 1};

int main() {
  ios_base::sync_with_stdio(false);
  
  int n, t;
  cin >> n >> t;
  cin.ignore();
  long long sum = 0;
  for(int it = 0; it < n; it++) {
    string buffer, f, s;
    vector<int> p;
    getline(cin, buffer);
    //cout << buffer << endl;
    stringstream ss(buffer);
    ss >> f;
    
    for(int i = 0; i < f.size(); i++) {
      if(f[i] != ':' && !('0' <= f[i] && f[i] <= '9')) {
        puts("CURRY GOAT!");
        return 0;
      }
    }
    
    for(int i = 0; i < f.size(); i++) {
      if(f[i] == ':') {
        p.push_back(i);
      }
    }
    if(p.size() > 3) {
      puts("CURRY GOAT!");
      return 0;
    }
    if(p.size()) {
      if(p[0] != 1 && p[0] != 2) {
        puts("CURRY GOAT!");
        return 0;
      }
    }
    
    //cerr << "cukers " << p.size() << endl;
    
    vector<int> num;
    num.assign(4, 0);
    if(p.size()) {
      num[0] = atoi(f.substr(0, p[0]).c_str());
    } else {
      num[0] = atoi(f.c_str());
    }
    for(int i = 1; i < p.size(); i++) {
      int d = p[i] - p[i - 1] - 1;
      if(d != 1 && d != 2) {
        puts("CURRY GOAT!");
        return 0;
      }
      num[i] = atoi(f.substr(p[i - 1] + 1, d).c_str());
    }
    
    //cerr << "boim kyaa" << endl;
    
    if(p.size()) {
      if(p.back() == buffer.size() - 1) {
        puts("CURRY GOAT!");
        return 0;
      } else {
        num[p.size()] = atoi(f.substr(p.back() + 1).c_str());
      }
    }
    
    //cerr << "jancok" << endl;
    
    if(!(0 <= num[1] && num[1] <= 59)) {
      puts("CURRY GOAT!");
      return 0;
    }
    if(!(0 <= num[2] && num[2] <= 59)) {
      puts("CURRY GOAT!");
      return 0;
    }
    if(!(0 <= num[3] && num[3] <= 999)) {
      puts("CURRY GOAT!");
      return 0;
    }
    
    if(ss >> s) {
      if(s != "AM" && s != "PM") {
        puts("CURRY GOAT!");
        return 0;
      }
      if(!(1 <= num[0] && num[0] <= 12)) {
        puts("CURRY GOAT!");
        return 0;
      }
      
      if(s == "PM" && num[0] != 12) {
        num[0] += 12;
      }
      if(s == "AM" && num[0] == 12) {
        num[0] = 0;
      }
      if(s == "PM" && num[0] == 12) {
        num[0] = 12;
      }
    } else {
      if(!(0 <= num[0] && num[0] <= 23)) {
        puts("CURRY GOAT!");
        return 0;
      }
    }
    if(ss >> s) {
      puts("CURRY GOAT!");
      return 0;
    }
    for(int i = 0; i < 4; i++) {
      sum += 1LL * num[i] * ping[i];
    }
  }
  sum /= n;
  vector<int> ans;
  ans.assign(4, 0);
  for(int i = 0; i < 4; i++) {
    ans[i] = sum / ping[i];
    sum = sum % ping[i];
  }
  if(t == 2) {
    for(int i = 0; i < 4; i++) {
      if(i < 3) {
        int f = ans[i] / 10;
        int s = ans[i] % 10;
        printf("%d%d:", f, s);
      } else {
        int f1 = ans[i] / 1000 % 10;
        int f2 = ans[i] / 100 % 10;
        int f3 = ans[i] / 10 % 10;
        int f4 = ans[i] / 1 % 10;
        printf("%d%d%d%d\n", f1, f2, f3, f4);
      }
    }
  } else {
    bool pm = 0;
    if(ans[0] == 0) {
      ans[0] = 12;
      pm = 0;
    } else if(ans[0] == 12) {
      ans[0] = 12;
      pm = 1;
    } else if(ans[0] > 12) {
      ans[0] -= 12;
      pm = 1;
    }
    for(int i = 0; i < 4; i++) {
      if(i < 3) {
        int f = ans[i] / 10;
        int s = ans[i] % 10;
        printf("%d%d:", f, s);
      } else {
        int f1 = ans[i] / 1000 % 10;
        int f2 = ans[i] / 100 % 10;
        int f3 = ans[i] / 10 % 10;
        int f4 = ans[i] / 1 % 10;
        printf("%d%d%d%d", f1, f2, f3, f4);
      }
    }
    printf(" ");
    if(pm) puts("PM");
    else puts("AM");
  }
  //cout << t << endl;
  return 0;
}
