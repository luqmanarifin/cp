#include <bits/stdc++.h>

using namespace std;

string str;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> split(char *phrase, string delimiter){
    vector<string> list;
    string s = string(phrase);
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return list;
}

int main() {
  int num = 0;
  while (getline(cin, str)) {
    if (num >= 2) {
      char* s = (char*) str.c_str();
      vector<string> tokens = split(s, "|");
      for (auto& it : tokens) it = trim(it);
      tokens[1] = to_string(num - 1);
      str = "|";
      for (int i = 0; i < tokens.size(); i++) {
        if (i == 0) continue;
        string it = tokens[i];
        str += " " + it + " |";
      }
    }
    cout << str << endl;
    num++;
    //printf("%d done\n", num);
  }
  return 0;
}
