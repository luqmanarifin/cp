#include <bits/stdc++.h>

using namespace std;

string buf;

int main() {
  int id = 1;
  while(getline(cin, buf)) {
    printf("INSERT INTO skpd (id, nama, created_at, updated_at, status) VALUES (\'%d\', \'%s\', CURRENT_TIMESTAMP, NULL,1);\n", id, buf.c_str()); 
    id++;
  }
  return 0;
}
