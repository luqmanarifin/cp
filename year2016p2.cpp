#include <bits/stdc++.h>

using namespace std;

const int N = 400;

string str[N];
string cuk[] = {"st", "nd", "rd"};

string part(int n) {
  int l = n % 10;
  int r = n / 10 % 10;
  if(r == 1) return "th";
  if(l <= 3) return cuk[l - 1];
  return "th";
}

int main() {
  //ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  cin.ignore();
  for(int i = 1; i <= n; i++) {
    getline(cin, str[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1) printf("\n");
    printf("On the %d%s day of Christmas my true love sent to me:\n", i, part(i).c_str());
    for(int j = i; j >= 1; j--) {
      if(i > 1 && j == 1) printf("and ");
      printf("%d %s\n", j, str[j].c_str());
    }
  }
  return 0;
}
