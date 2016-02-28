#include <bits/stdc++.h>

using namespace std;

class Bapak {
public:
  Bapak() {
    puts("Bapak telah lahir");
  }
  virtual void cok() {
    cout << "cok punya bapak" << endl;
  }
private:
  
};

class Anak : public Bapak {
public:
  Anak() {
    puts("Anak telah lahir");
  }
  virtual void cok() {
    cout << "cok punya anak" << endl;
  }
private:

};

int main() {
  Anak a;
  vector<Bapak> kumps;
  kumps.push_back(a);
  
  return 0;
}