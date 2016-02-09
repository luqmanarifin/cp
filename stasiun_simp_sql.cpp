#include <bits/stdc++.h>

using namespace std;

string code(string str) {
  string ret;
  for(int i = 0; i < str.length(); i++) {
    int c = str[i] - 'a', C = str[i] - 'A';
    if(0 <= C && C < 26) c = C;
    ret.push_back(c + 'A');
  }
  return ret;
}

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  string buffer, word;
  while(getline(cin, buffer)) {
    stringstream ss(buffer);
    vector<string> sentence;
    while(ss >> word) {
      sentence.push_back(word);
    }
    sentence.back() = code(sentence.back());
    cout << "(\"" << sentence.back() << "\", \"" << get(1, 6) << "\", \"" << get(1, 900) << "\", \"";
    for(int i = 0; i < (int) sentence.size() - 1; i++) {
      if(i) cout << " ";
      cout << sentence[i];
    }
    cout << "\"),"<< endl;
  }
  
  return 0;
}
