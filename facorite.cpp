#include <bits/stdc++.h>

using namespace std;

const int N = 5;

// rock
// paper
// scissors
// lizard
// spock

string str[] = {
  "Rock",
  "Paper",
  "Scissors",
  "Lizard",
  "Spock"
};

map<string, int> id;

bool twin[N][N] = {
  {0, 0, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 0, 1},
  {1, 0, 1, 0, 0}
};

int next_tei[N] = {1, 2, 4, 0, 3};

// is alice win
bool win[30];
bool tei[30];
bool done[30];
int memo[30];

// find win (Alice) and tei for n games
pair<long long, long long> find(int a, int b, long long n) {
  long long awin = 0, atie = 0;
  for(int i = 0; i < n; i++) {
    bool alice_win = twin[a][b];
    bool alice_tie = (a == b);
    if(alice_win) awin++;
    if(alice_tie) atie++;
    
    if(alice_win) {
      
    } else if(alice_tie) {
      a = next_tei[a];
    } else {
      a = next_tei[b];
    }
    
    if(b == 4) {
      if(!alice_win && !alice_tie) {
        b = 0;
      } else if(alice_tie) {
        b = 3;
      } else {
        b = 1;
      }
    } else {
      b = 4;
    }
  }
  return make_pair(awin, atie);
}

int main() {
  for(int i = 0; i < 5; i++) {
    id[str[i]] = i;
  }
  int t;
  cin >> t;
  while(t--) {
    string sa, sb;
    long long n;
    cin >> sa >> sb >> n;
    int a = id[sa];
    int b = id[sb];
    memset(done, 0, sizeof(done));
    
    long long awin = 0, atei = 0;
    for(int i = 1; i <= 30 && i <= n; i++) {
      //printf("%s %s\n", str[a].c_str(), str[b].c_str());
      int code = a * 5 + b;
      if(done[code]) {
        long long size = i - memo[code];
        long long times = (n - i + 1) / size;
        long long cwin = 0, ctei = 0;
        for(int j = memo[code]; j < i; j++) {
          cwin += win[j];
          ctei += tei[j];
        }
        awin += cwin * times;
        atei += ctei * times;
        pair<long long, long long> tmp = find(a, b, n - i + 1 - size * times);
        awin += tmp.first;
        atei += tmp.second;
        break;
      }
      memo[code] = i;
      done[code] = 1;
      bool alice_win = twin[a][b];
      win[i] = alice_win;
      tei[i] = (a == b);
      awin += win[i];
      atei += tei[i];
      if(alice_win) {
        
      } else if(tei[i]) {
        a = next_tei[a];
      } else {
        a = next_tei[b];
      }
      
      if(b == 4) {
        if(!alice_win && !tei[i]) {
          b = 0;
        } else if(tei[i]) {
          b = 3;
        } else {
          b = 1;
        }
      } else {
        b = 4;
      }
    }
    long long bwin = n - awin - atei;
    if(awin > bwin) {
      printf("Alice wins, by winning %lld game(s) and tying %lld game(s)\n", awin, atei);
    } else if(awin < bwin) {
      printf("Bob wins, by winning %lld game(s) and tying %lld game(s)\n", bwin, atei);
    } else {
      printf("Alice and Bob tie, each winning %lld game(s) and tying %lld game(s)\n", awin, atei);
    }
  }
  
  return 0;
}
