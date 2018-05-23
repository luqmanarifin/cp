#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int> > ii;
set<ii>  l;

int pngkat(int a, int b){
    return (a-b) * (a-b);
}

int kali(int a) {
    return a*a;
}

int main(){
    int tc;
    int x,y,r;
    string p;

    scanf("%d", &tc);
    for(int t=0;t<tc;t++) {
        cin >> p >> x >> y >> r;

        if(x<0 || y<0 || x>1000 || y>1000) {
            printf("No\n");
            continue;
        }

        if(p=="A") {
            if(l.empty()){
                l.insert(make_pair(r, make_pair(x, y)));
                printf("Ok\n");
                continue;
            }

            //udah ada
            if(l.find(make_pair(r, make_pair(x, y)))!=l.end()) {
                printf("No\n");
            } else {
                int found = 0;
                set<ii> :: iterator it;
                for(it = l.begin(); it!=l.end(); ++it){
                    ii test = *it;
                    int jarak = pngkat(test.second.first, x) + pngkat(test.second.second, y);

                    if(jarak < kali(test.first + r)) {
                        found = 1;
                    }
                }
                if(found) {
                    printf("No\n");
                } else {
                    printf("Ok\n");
                    l.insert(make_pair(r, make_pair(x, y)));
                }
            }
        } else {
            if(l.find(make_pair(r, make_pair(x, y)))!=l.end()) {
                l.erase(make_pair(r, make_pair(x, y)));
                printf("Ok\n");
            } else printf("No\n");
        }
    }
    return 0;
}
