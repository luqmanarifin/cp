// set cheatsheet
int main() {
  // deklarasi, sorted dari yg terkecil
  multiset<int> s;
  
  // insert
  s.insert(3);
  
  // erase semua elemen 3
  s.erase(3);
  
  // erase elemen 3 tapi hanya 1 aja
  s.erase(s.find(3));
  
  // size
  s.size();
  
  // elemen pertana
  int x = *(s.begin());
  
  // elemen terakhir
  auto it = s.end(); it--; int x = *it;
  
  // lower_bound nilai x
  auto it = s.lower_bound(x);
  int x;
  if (it != s.end()) {
    x = *it;
  } else {
    // ga ada lower_bound
  }
  
  // upper_bound nilai x
  auto it = s.upper_bound(x);
  if (it != s.begin()) {
    
  }
  int x;
  if (it != s.end()) {
    x = *it;
  } else {
    // ga ada lower_bound
  }
  
  
}