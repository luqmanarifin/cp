#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

vector<string> a, b;
char buffer[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  char aname[] = "salah.out";
  char bname[] = "correct.out";
  FILE *aFile;
  aFile = fopen(aname, "r");
  while(fgets(buffer, MAX, aFile)) {
    a.push_back((string) buffer);
  }
  FILE *bFile;
  bFile = fopen(bname, "r");
  while(fgets(buffer, MAX, bFile)) {
    b.push_back((string) buffer);
  }
  if(a.size() == b.size()) {
    for(int i = 0; i < a.size(); i++) {
      if(a[i] != b[i]) {
        printf("%s tidak sama dengan %s, pada baris %d\n\n", aname, bname, i + 1);
        printf("%s :\n%s\n", aname, a[i].c_str());
        printf("%s :\n%s\n", bname, b[i].c_str());
        return 0;
      }
    }
    printf("CORRECT! %s sama dengan %s\n", aname, bname);
  } else {
    printf("%s tidak sama dengan %s, jumlah line berbeda\n", aname, bname);
  }

  return 0;
}
