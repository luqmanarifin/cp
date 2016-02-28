// Bismillahirrahmanirrahim
// AgriCoder IPB
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>

using namespace std;

#define FOR(i, agri, coder) for (int i = (int)agri; i <= (int)coder; i++)
#define REP(agri,coder) for (int agri = 0; agri < (int)coder; agri++)
#define FOREACH(i,agricoder) for (typeof((agricoder).end()) i = (agricoder).begin(); i != (agricoder).end(); ++i)
#define RESET(agri,coder) memset(agri, coder, sizeof(agri))
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define NL printf("==========================\n")

int arahbar[8] = {0,1,0,-1,1,1,-1,-1};
int arahkol[8] = {1,0,-1,0,1,-1,-1,1};
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

bool ispalindrom(string s) {
    int panjang = s.length();
    REP(i,panjang/2) {
        if (s[i]!=s[panjang-i-1]) return false;
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    int len = s.length();
    bool sudah = false;

    REP(i,len+1) { // coba masukkin satu2
        FOR(ch,0,25) {
            string temp = s;
            temp.insert(temp.begin()+i , (char) (ch+95) );
            if (ispalindrom(temp)) {
                cout << temp << endl;
                sudah = true;
                goto langsung;
                break;
            }
        }
    }
    langsung:
    if (!sudah) printf("NA\n");
	 cout << int('a') << endl;
    return 0;
}
// Alhamdulillahirabbilalamin