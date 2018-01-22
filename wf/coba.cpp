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
  getline(cin, str);
  char* s = (char*) str.c_str();
  vector<string> tokens = split(s, "|");
  for (auto it : tokens) cout << "asu: " << it << endl;
  return 0;
}
