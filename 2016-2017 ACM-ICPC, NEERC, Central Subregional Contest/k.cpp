#include <bits/stdc++.h>

using namespace std;

struct item {
  item() {}
  item(bool cons, string var) : cons(cons), var(var) {}
  bool operator==(const item& other) const {
    return cons == other.cons && var == other.var;
  }
  bool operator!=(const item& other) const {
    return !(*this == other); 
  }
  bool cons;
  string var;
};

struct command {
  command() {}
  command(string com, item arg1) : com(com), arg1(arg1){}
  command(string com, item arg1, item arg2) : com(com), arg1(arg1), arg2(arg2) {}
  string com;
  item arg1;
  item arg2;
};

const int N = 5e4 + 5;

int l[N], r[N], n;

bool ada(int st, int cnt) {
  int now = st;
  for (int i = 1; i < cnt; i++) {
    now = r[now];
    if (now > n) return 0;
  }
  return 1;
}

void remove(int st) {
  r[l[st]] = r[st];
  l[r[st]] = l[st];
}

void remove(int st, int cnt) {
  for (int i = 0; i < cnt; i++) {
    remove(st);
    st = r[st];
  }
}  

int mundur(int st, int cnt) {
  for (int i = 0; i < cnt; i++) {
    st = l[st];
    if (st == 0) return r[0];
  }
  return st;
}

bool is_constant(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F')) {
      
    } else {
      return 0;
    }
  }
  return 1;
}

command s[N];

bool mov(int now) {
  // kesediaan
  if (!ada(now, 2)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < 2; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "POP"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  
  // comment
  
  // constant atau bukan
  
  // hapus command lain
  s[now] = command("MOV", p[1].arg1, p[0].arg1);
  remove(r[now], 1);
  
  return 1;
}

bool mov_cons(int now) {
  // kesediaan
  if (!ada(now, 2)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < 2; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"XOR", "ADD"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  if (p[0].arg1 != p[0].arg2 || p[0].arg2 != p[1].arg1) return 0;
  
  // comment
  
  // constant atau bukan
  vector<int> must_cons = {1};
  vector<int> no_cons = {0};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("MOV", p[0].arg1, p[1].arg2);
  remove(r[now], 1);
  
  return 1;
}

bool add(int now) {
  // kesediaan
  int need = 4;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "MOV", "ADD", "POP"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  if (p[0].arg1 != p[1].arg1 || p[1].arg1 != p[2].arg2 || p[2].arg2 != p[3].arg1) return 0;
  
  // comment
  if (p[2].arg1 == p[2].arg2) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {};
  vector<int> no_cons = {1, 2};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("ADD", p[2].arg1, p[1].arg2);
  remove(r[now], need - 1);
  
  return 1;
}

bool add_cons(int now) {
  // kesediaan
  int need = 5;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "MOV", "ADD", "MOV", "POP"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  if (p[2].arg2 != p[3].arg1) return 0;
  if (p[0].arg1 != p[1].arg1 || p[1].arg1 != p[2].arg1 || p[2].arg1 != p[3].arg2 || p[3].arg2 != p[4].arg1) return 0; 
  
  // comment
  if (p[2].arg1 == p[2].arg2) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {1};
  vector<int> no_cons = {2, 3};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("ADD", p[2].arg2, p[1].arg2);
  remove(r[now], need - 1);
  
  return 1;
}

bool xorr(int now) {
  // kesediaan
  int need = 7;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "MOV", "XOR", "XOR", "MOV", "XOR", "POP"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  vector<item> rz = {p[0].arg1, p[1].arg1, p[2].arg1, p[3].arg2, p[4].arg1, p[5].arg2, p[6].arg1};
  for (auto it : rz) if (it != rz[0]) return 0;
  vector<item> rx = {p[3].arg1, p[5].arg1};
  for (auto it : rx) if (it != rx[0]) return 0;
  vector<item> rnd = {p[2].arg2, p[4].arg2};
  for (auto it : rnd) if (it != rnd[0]) return 0;
  
  // comment
  if (rz[0] == rx[0]) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {2, 4};
  vector<int> no_cons = {1, 3, 5};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("XOR", rx[0], p[1].arg2);
  remove(r[now], need - 1);
  
  return 1;
}

bool xorr_cons(int now) {
  // kesediaan
  int need = 5;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "XOR", "XOR", "POP", "XOR"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  vector<item> rz = {p[0].arg1, p[1].arg1, p[2].arg2, p[3].arg1, p[4].arg2};
  for (auto it : rz) if (it != rz[0]) return 0;
  vector<item> rx = {p[2].arg1, p[4].arg1};
  for (auto it : rx) if (it != rx[0]) return 0;
  
  // comment
  if (rz[0] == rx[0]) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {1};
  vector<int> no_cons = {2, 4};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("XOR", rx[0], p[1].arg2);
  remove(r[now], need - 1);
  
  return 1;
}

bool push(int now) {
  // kesediaan
  int need = 7;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"PUSH", "MOV", "POP", "PUSH", "XOR", "XOR", "XOR"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  vector<item> rz = {p[1].arg2, p[2].arg1, p[3].arg1, p[4].arg2, p[5].arg1, p[6].arg2};
  for (auto it : rz) if (it != rz[0]) return 0;
  vector<item> rx = {p[0].arg1, p[1].arg1, p[4].arg1, p[5].arg2, p[6].arg1};
  for (auto it : rx) if (it != rx[0]) return 0;
  
  // comment
  if (rz[0] == rx[0]) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {};
  vector<int> no_cons = {1, 4, 5, 6};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("PUSH", rx[0]);
  remove(r[now], need - 1);
  
  return 1;
}

bool pop(int now) {
  // kesediaan
  int need = 5;
  if (!ada(now, need)) return 0;
  vector<command> p;
  int pt = now;
  for (int i = 0; i < need; i++) {
    p.push_back(s[pt]);
    pt = r[pt];
  }
  
  // command
  vector<string> str = {"MOV", "POP", "XOR", "XOR", "XOR"};
  for (int i = 0; i < p.size(); i++) if (str[i] != p[i].com) return 0;
  
  // variabel sama
  vector<item> rz = {p[0].arg2, p[1].arg1, p[2].arg2, p[3].arg1, p[4].arg2};
  for (auto it : rz) if (it != rz[0]) return 0;
  vector<item> rx = {p[0].arg1, p[2].arg1, p[3].arg2, p[4].arg1};
  for (auto it : rx) if (it != rx[0]) return 0;
  
  // comment
  if (rz[0] == rx[0]) return 0;
  
  // constant atau bukan
  vector<int> must_cons = {};
  vector<int> no_cons = {0, 2, 3, 4};
  for (auto it : must_cons) if (p[it].arg2.cons == 0) return 0;
  for (auto it : no_cons) if (p[it].arg2.cons == 1) return 1;
  
  // hapus command lain
  s[now] = command("POP", rx[0]);
  remove(r[now], need - 1);
  
  return 1;
}

#define LOCAL

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < N; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string com, arg1, arg2;
    cin >> com;
    if (com == "PUSH" || com == "POP") {
      cin >> arg1;
      s[i] = command(com, item(0, arg1));
      assert(!is_constant(arg1));
    } else {
      cin >> arg1 >> arg2;
      arg1 = arg1.substr(0, arg1.size() - 1);
      if (is_constant(arg2) && arg2.size() == 1) {
        arg2 = "0" + arg2;
      }
      s[i] = command(com, item(is_constant(arg1), arg1), item(is_constant(arg2), arg2));
    }
  }
  int now = r[0];
  while (now <= n) {
    //printf("%d\n", now);
    if (push(now)) {
      now = mundur(now, 6);
    } else if (xorr(now)) {
      now = mundur(now, 6);
    } else if (add_cons(now)) {
      now = mundur(now, 6);
    } else if (xorr_cons(now)) {
      now = mundur(now, 6);
    } else if (pop(now)) {
      now = mundur(now, 6);
    } else if (add(now)) {
      now = mundur(now, 6);
    } else if (mov_cons(now)) {
      now = mundur(now, 6);
    } else if (mov(now)) {
      now = mundur(now, 6);
    } else {
      now = r[now];
    }
  }
  int ada = 0;
  now = r[0];
  while (now <= n) {
    ada++;
    now = r[now];
  }
  printf("%d\n", ada);
  
  now = r[0];
  while (now <= n) {
    if (s[now].com == "PUSH" || s[now].com == "POP") {
      printf("%s %s\n", s[now].com.c_str(), s[now].arg1.var.c_str());
    } else {
      printf("%s %s, %s\n", s[now].com.c_str(), s[now].arg1.var.c_str(), s[now].arg2.var.c_str());
    }
    now = r[now];
  }
  return 0;
}
