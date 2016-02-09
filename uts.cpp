#include <bits/stdc++.h>

using namespace std;

class Bapak {
public:
  Bapak() {
  
  }
  Bapak(const Bapak&) {
  
  }
  virtual void print() {
    cout << "bapak" << endl;
  }
private:
  
};

class Anak : public Bapak {
public:
  Anak() {
  
  }
  Anak(const Anak&) {
  
  }
  Anak(const Bapak&) {
  
  }
  virtual void print() {
    cout << "anak" << endl;
  }
  void f(Bapak& b) {
    Anak aa = (Anak) b;
    aa.print();
  }
private:

};

int main() {
  Anak a;
  Bapak b;
  a.f(b);
  
  return 0;
}