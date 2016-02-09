#include <bits/stdc++.h>

using namespace std;

stack<int> st;
string type;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  bool now = 1;
  cin >> n;
  cin.ignore();
  while(n--) {
    string temp;
    getline(cin, temp);
    int len = temp.length();
    for(int i = 0; i < len; i++) {
      if(temp.substr(i, 3) == "try" && i + 3 <= len) {
        st.push(now);
        break;
      }
      if(temp.substr(i, 5) == "throw" && i + 5 <= len) {
        i += 5;
        while(temp[i] == ' ' || temp[i] == '(') i++;
        string tt = "";
        while(temp[i] != ' ' && i < len && temp[i] != ')') {
          tt.push_back(temp[i]);
          i++;
        }
        type = tt;
        now = 0;
        break;
      }
      if(temp.substr(i, 5) == "catch" && i + 5 <= len) {
        int top = -1;
        if(!st.empty()) {
          top = st.top();
          st.pop();
        }
        i += 5;
        if(top == 1 && now == 0) {
          while(temp[i] == ' ' || temp[i] == '(') i++;
          string tt = "";
          while(temp[i] != ',' && temp[i] != ' ' && i < len) {
            tt.push_back(temp[i]);
            i++;
          }
          if(tt == type) {
            while(temp[i] == ' ' || temp[i] == ',' || temp[i] == '"') {
              i++;
              if(temp[i - 1] == '"') {
                break;
              }
            }
            while(temp[i] != '"') {
              printf("%c", temp[i]);
              i++;
            }
            printf("\n");
            return 0;
          }
        }
        break;
      }
    }
  }
  puts("Unhandled Exception");
  return 0;
}