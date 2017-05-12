#include <bits/stdc++.h>

using namespace std;

string buf;

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  stack<string> st;
  st.push(s);
  while (q--) {
    cin >> buf;
    if (buf == "ADD") {
      cin >> s;
      string jadi = st.top() + s;
      st.push(jadi);
    } else if (buf == "DELETE") {
      string jadi = st.top().substr(0, st.top().length() - 1);
      st.push(jadi);
    } else if (buf == "INSERT") {
      string sisip, sebelum;
      cin >> sisip >> sebelum;
      string bef = st.top();
      string now;
      for (int i = 0; i < bef.length(); i++) {
        if (i >= sebelum.length()) {
          //cout<< bef.substr(i - sebelum.length(), sebelum.length()) << endl;
          if (bef.substr(i - sebelum.length(), sebelum.length()) == sebelum) {
            //cout << "COK" << endl;
            now += sisip;
          }
        }
        now += bef[i];
      }
      st.push(now);
    } else {
      st.pop();
    }
  }
  cout << st.top() << endl;
  return 0;
}