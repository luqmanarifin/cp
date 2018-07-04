#include <bits/stdc++.h>
#include <string>     // std::string, std::to_string

using namespace std;

int main() {
  for (int i = 3; i <= 10; i++) {
    string in = "osn-2018-pajel_" + to_string(i) + ".in";
    string out = "osn-2018-pajel_" + to_string(i) + ".out";
    string cmd = "./e < " + in + " > " + out;
    system(cmd.c_str());
  }

  return 0;
}
