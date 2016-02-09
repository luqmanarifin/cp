#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  Stack<int> st;
  for(int i = 0; i < 5; i++) {
    st.push(i);
  }
  while(!st.isEmpty()) {
    int a;
    st.pop(a);
    cout << a << endl;
  }
  
  return 0;
}
