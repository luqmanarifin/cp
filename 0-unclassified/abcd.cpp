#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define ll long long
 
vector<string> list_string[25];
vector<ll> hash_list[25][2];
 
bool skip[20000];
int main() {
 
    // std::ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    for(int kasus = 1; kasus<=tc; kasus++) {
 
        printf("Case #%d: ",kasus);
 
        int n;
        cin >> n;
        for(int i=1; i<=20; i++) {
            list_string[i].clear();
            for(int j =0 ; j<2; j++) {
                hash_list[i][j].clear();
            }
        }
        int st =0 ;
        for(int i = 0; i< n; i++) {
            string temp;
            cin >> temp;
            int pjg = temp.length();
            st = max(st,pjg);
            list_string[pjg].push_back(temp);
            ll hash =0, hash2 ;
            for(int j =0 ; j < (int) temp.length()-1; j++) {
                hash*= 31;
                hash+= (temp[j]-'A'+1);
            }
            hash_list[pjg][0].push_back(hash);
            hash2=hash*31;
            hash2+=temp[pjg-1]-'A'+1;
            hash_list[pjg][1].push_back(hash2);
            //cout << temp << '=' << hash << ',' << hash2 << '\n';
        }
        int v =0;
        map<ll, int> last;
        for(int pjg = st; pjg > 0; pjg--) {
            vector<string> &lx = list_string[pjg];
            //cout << "PANJANG " << pjg << '\n';
            for(int i =0 ; i < (int)lx.size(); i++) {
                skip[i] = false;
                ll hash_full = hash_list[pjg][1][i];
                if(last[hash_full]>0) {
                    v++;
                    last[hash_full]--;
                    skip[i] = true;
                } else {
                    //cout << "TIDAK ADA " << hash_full << '\n';
                }
            }
            last.clear();
            for(int i =0 ; i < (int)lx.size(); i++) {
                if(skip[i]) {
                    continue;
                }
                ll hash_gk_full = hash_list[pjg][0][i];
                last[hash_gk_full]++;
                // cout << "MASUKKAN " << lx[i] << ' ' << hash_gk_full << '\n';
            }
        }
 
        printf("%d\n",v);
 
    }
}