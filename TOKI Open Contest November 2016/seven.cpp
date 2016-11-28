#include <bits/stdc++.h>

using namespace std;

string str[] =  {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string num = s.substr(0, s.size() - 1);
    char c = s[s.size() - 1];
    for (int i = 0; i < 13; i++) {
      if (num == str[i]) {
        bool awal = 1;
        for (int j = i - 1; j >= 0; j--) {
          if (!awal) printf(" ");
          printf("%s%c", str[j].c_str(), c);
          awal = 0;
        }
        for (int j = i + 1; j < 13; j++) {
          if (!awal) printf(" ");
          printf("%s%c", str[j].c_str(), c);
          awal = 0;
        }
        
        printf("\n");
      }
    }
  }

  return 0;
}
