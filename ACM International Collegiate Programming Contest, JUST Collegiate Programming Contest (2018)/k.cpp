#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

string get_key(string& s) {
  int at = s.find('=');
  return s.substr(0, at);
}

string get_value(string& s) {
  int b = s.find('{');
  int e = s.find('}');
  return s.substr(b + 1, e - b - 1);
}

string format_author(string& s) {
  string ret = "";
  int par = 0;
  // cout << s << endl;
  for (int i = 0; i < s.length(); i++) {
    int j = i;
    while (j < s.length() && s[j] != ' ') {
      j++;
    }
    if (par % 2 == 0 && par > 0) {
      ret += ", ";
    }
    if (par % 2 == 0) {
      ret += s[i];
      ret += s[i + 1];
    } else {
      ret += ". ";
      ret += s[i];
    }
    // printf("%d %d\n", i, j);
    i = j;
    par++;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
      map<string, string> m;
      string str;
      getline(cin, str);
      for (int i = 0; i < 8; i++) {
        getline(cin, str);
        string key = get_key(str);
        string value = get_value(str);
        m[key] = value;
      }
      getline(cin, str);

      printf("%s. %s. %s. %s;%s(%s):%s.\n",
        format_author(m["author"]).c_str(),
        m["title"].c_str(),
        m["journal"].c_str(),
        m["year"].c_str(),
        m["volume"].c_str(),
        m["number"].c_str(),
        m["pages"].c_str()
      );
    }
  }

  return 0;
}
