#include <bits/stdc++.h>

using namespace std;

string sat[] = {
  "zero",	 
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"
};

string bel[] = {
  "ten", 	  	 
  "eleven", 	  	 
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen"
};

string pul[] = {
  "twenty",
  "thirty",
  "forty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety"
};

int main() {
  int n;
  scanf("%d", &n);
  if(n < 20) {
    if(n < 10) {
      cout << sat[n] << endl;
    } else {
      cout << bel[n - 10] << endl;
    }
  } else {
    cout << pul[(n - 20) / 10];
    if(n % 10) {
      cout << "-" << sat[n % 10] << endl;
    }
  }
  return 0;
}
