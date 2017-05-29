#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

map<string, int> mp;
string name[N];
int cnt;

set<pair<int, int>> s[N];

void add(string str) {
  mp[str] = cnt;
  name[cnt] = str;
  cnt++;
}

pair<int, int> parse(string str) {
  int pos = str.find('(');
  if (pos == string::npos) {
    string a = str;
    if (!mp.count(a)) add(a);
    return {mp[a], 0};
  } else {
    string a = str.substr(0, pos);
    if (!mp.count(a)) add(a);
    int num = 0;
    for (int i = pos + 1; i + 1 < str.size(); i++) {
      num = num * 10 + str[i] - '0';
    }
    return {mp[a], num};
  }
}

void erase(int at, int val) {
  pair<int, int> rem;
  auto it = s[at].lower_bound(make_pair(val, inf));
  it--;
  rem = *it;
  assert(it->first <= val && val <= it->second);
  if (it->first < val) {
    s[at].insert(make_pair(it->first, val - 1));
  }
  if (val < it->second) {
    s[at].insert(make_pair(val + 1, it->second));
  }
  s[at].erase(rem);
}

int empty(int at, int val) {
  auto it = s[at].lower_bound(make_pair(val, inf));
  if (it != s[at].begin()) {
    it--;
    if (it->second < val) {
      return val;
    } else {
      return it->second + 1;
    }
  } else {
    return val;
  }
}

void add(int at, int val) {
  vector<pair<int, int>> rem;
  int l = val, r = val;
  auto it = s[at].lower_bound(make_pair(val, inf));
  if (it != s[at].end()) {
    if (val + 1 == it->first) {
      rem.push_back(*it);
      r = max(r, it->second);
    }
  }
  if (it != s[at].begin()) {
    it--;
    if (it->second + 1 == val) {
      rem.push_back(*it);
      l = min(l, it->first);
    }
  }
  for (auto i : rem) s[at].erase(i);
  s[at].insert(make_pair(l, r));
}

void del(string str) {
  pair<int, int> p = parse(str);
  erase(p.first, p.second);
}

vector<int> dig(int num) {
  vector<int> ret;
  while (num) {
    ret.push_back(num % 10);
    num /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

string create(string str) {
  pair<int, int> p = parse(str);
  int num = empty(p.first, p.second);
  add(p.first, num);
  string ret = name[p.first];
  if (num > 0) {
    ret += '(';
    vector<int> digit = dig(num);
    for (auto it : digit) {
      ret += (it + '0');
    }
    ret += ')';
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string cmd, str, be;
    cin >> cmd >> str;
    if (cmd == "crt") {
      string be = create(str);
      printf("+ %s\n", be.c_str());
    } else if (cmd == "del") {
      del(str);
      printf("- %s\n", str.c_str());
    } else {
      cin >> be;
      del(str);
      be = create(be);
      printf("r %s -> %s\n", str.c_str(), be.c_str());
    }
  }
  return 0;
}
