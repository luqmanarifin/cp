#include <bits/stdc++.h>

using namespace std;

map<string, map<string, int>> MP;

// 1, a win over b
// 0, tied
// -1, b win over
int win(int a, int b) {
  if (abs(a - b) < 2) {
    if (a > b) {
      return 1;
    } else if (a == b) {
      return 0;
    } else {
      return -1;
    }
  }
  if (a == 2) {
    return -1;
  } else {
    return 1;
  }
}

int main() {
  MP["cs"]["Kamen"] = 2;
  MP["cs"]["Nuzky"] = 1;
  MP["cs"]["Papir"] = 0;
  
  MP["en"]["Rock"] = 2;
  MP["en"]["Scissors"] = 1;
  MP["en"]["Paper"] = 0;
  
  MP["fr"]["Pierre"] = 2;
  MP["fr"]["Ciseaux"] = 1;
  MP["fr"]["Feuille"] = 0;
  
  MP["de"]["Stein"] = 2;
  MP["de"]["Schere"] = 1;
  MP["de"]["Papier"] = 0;
  
  MP["hu"]["Ko"] = 2;
  MP["hu"]["Koe"] = 2;
  MP["hu"]["Ollo"] = 1;
  MP["hu"]["Olloo"] = 1;
  MP["hu"]["Papir"] = 0;
  
  MP["it"]["Sasso"] = 2;
  MP["it"]["Roccia"] = 2;
  MP["it"]["Forbice"] = 1;
  MP["it"]["Carta"] = 0;
  MP["it"]["Rete"] = 0;
  
  MP["jp"]["Guu"] = 2;
  MP["jp"]["Choki"] = 1;
  MP["jp"]["Paa"] = 0;
  
  MP["pl"]["Kamien"] = 2;
  MP["pl"]["Nozyce"] = 1;
  MP["pl"]["Papier"] = 0;
  
  MP["es"]["Piedra"] = 2;
  MP["es"]["Tijera"] = 1;
  MP["es"]["Papel"] = 0;
  
  int tt = 0;
  string a, b;
  do {
    ++tt;
    string sa, sb;
    string na, nb;
    cin >> sa >> na >> sb >> nb;
    int va = 0, vb = 0;
    while (cin >> a) {
      if (a[0] == '-' || a[0] == '.') break;
      cin >> b;
      int c = win(MP[sa][a], MP[sb][b]);
      if (c == 1) {
        va++;
      } else if (c == -1) {
        vb++;
      }
    }
    printf("Game #%d:\n", tt);
    printf("%s: %d ", na.c_str(), va); puts(va == 1? "point" : "points");
    printf("%s: %d ", nb.c_str(), vb); puts(vb == 1? "point" : "points");
    if (va == vb) {
      puts("TIED GAME");
    } else {
      printf("WINNER: ");
      if (va > vb) {
        printf("%s\n", na.c_str());
      } else {
        printf("%s\n", nb.c_str());
      }
    }
    puts("");
    
  } while (a[0] == '-');
  
  return 0;
}