    /*-------------icalFikr's template v1.2 BETA-------------*/
     
    #include <iostream>
    #include <cstdio>
    #include <fstream>
    #include <istream>
    #include <ostream>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <list>
    #include <map>
    #include <bitset>
    #include <stack>
    #include <queue>
    #include <deque>
    #include <set>
    #include <cstdlib>
    #include <cmath>
    #include <complex>
    #include <algorithm>
    #include <iomanip>
    #include <cstddef>
    #include <cctype>
    #include <utility>
     
    /* Abbreviations */
    #define pb push_back
    #define pob pop_back
    #define fs first
    #define sc second
    #define mp make_pair
    #define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
    #define FORD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
    #define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #define close fclose(stdin); fclose(stdout);
    #define sz size()
    #define reset(x,N) memset(x,N,sizeof(x))
    #define nl puts("")
    #define gc getchar()
    #define PI acos(-1)
     
    using namespace std;
    typedef double db;
    typedef long long ll;
    typedef pair <int,int> ii;
    typedef pair <string,int> si;
    typedef vector <ii> vii;
    typedef vector <int> vi;
    typedef vector <char> vc;
    typedef vi::iterator it;
     
    /* Template function(s) */
    template <typename T>
    inline T getnum() {
    T num=0; char c;
    do { c=gc; }
    while (c!=EOF && c==' ' && c=='\n' && c=='\t');
     
    int sign=(c=='-' ? -1 : 1);
    if (c!='-') num+=(c-'0');
     
    while ( (c=gc)!=EOF && c!='\n' && c!='\t' && c!=' ') {
    num*=10; num+=(c-'0');
    }
    num*=sign; return num;
    }
    inline string getstr() {
    string str; char k;
    while( (k=gc)==' ' || k=='\n' )
    {
    k=gc;
    if ( k==' ' || k=='\n' ) continue;
    else break;
    }
    while((k=gc)!=EOF &&k!='\n' && k!='\t'
    && k!='\v' && k!='\0' && k!=' ')
    str.pb(k);
    return str;
    }
     
    /*-------------end of template-------------*/
    int cfg[100100];
    vector <char> lala;
     
    int main()
    {
    reset(cfg,0);
    int x,o; cin>>o>>x;
     
    int t;
     
    if (o<x) {
    t=min(x,o);
    FOR(i,0,t-1)
    {cfg[2*i]=-1; cfg[2*i+1]=1;}
    o-=t; x-=t;
    if (x) {	
    cfg[2*t]=-1; x--;
    int i=0;
    while (x) {
    if (cfg[i]<0)
    {cfg[i]--; x--;}
    i++;
    if (i>2*t) i=0;
    }
    }
    } else {
    int i=0;
    if (x) {cfg[i]=-x/2; x+=cfg[i]; i++;}
    cfg[i]=o; o=0; i++;
    if (x) {cfg[i]=-x; x=0; i++;}
    }
     
    ll ans=0; int i=0;
    while (cfg[i]) {
    t=cfg[i];
    if (t>0) {
    ans+=(ll)t*t;
    while (t) {lala.pb('o'); t--;}
    } else {
    ans-=(ll)(t*t);
    while (t) {lala.pb('x'); t++;}
    }
    i++;
    }
    cout<<ans; nl;
    FOR(i,0,lala.sz-1) putchar(lala[i]);
     
    return 0;
    }