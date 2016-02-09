#include <bits/stdc++.h>

using namespace std;

string str[] = {
  "Normal"	
  ,"Fighting"	
  ,"Flying"
  ,"Poison"
  ,"Ground"	
  ,"Rock"	
  ,"Bug"	
  ,"Ghost"	
  ,"Steel"	
  ,"Fire"	
  ,"Water"	
  ,"Grass"	
  ,"Electric"	
  ,"Psychic"	
  ,"Ice"	
  ,"Dragon"	
  ,"Dark"	
  ,"Fairy"	
  ,"Legend"	
};

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  while(n--) {
    string name;
    int a;
    cin >> name >> a;
    bool ada = 0;
    for(int i = 0; i < 19; i++) {
      if(name == str[i]) {
        int val = (i == 18? 10000 : (i + 1) * 100);
        if(i == 18) {
          printf("%s master ball\n", name.c_str());
          ans += 100 * val;
        } else {
          if(1000 >= a) {
            printf("%s poke ball\n", name.c_str());
            ans += val;
          } else if(2000 >= a) {
            printf("%s great ball\n", name.c_str());
            ans += 2 * val;
          } else if(3000 >= a) {
            printf("%s ultra ball\n", name.c_str());
            ans += 3 * val;
          } else {
            assert(0);
          }
        }
        ada = 1;
        break;
      }
    }
    assert(ada);
  }
  cout << ans << endl;
  return 0;
}
