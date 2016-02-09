#include <bits/stdc++.h>
#define loop(a,b,c) for(int a=b;a<c;a++)
#define loopm(a,b) for(int a=b;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f front()
#define b back()
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#define reset(a,b) memset(a,b,sizeof a)
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef map<int,int> mii;
typedef map<string,int> msi;
 
//templates end here
 
vii v[10001];
 
int main()
{
	int N;
	int T;
	scanf("%d",&T);
	loop(i,1,T+1)
	{
		int maks=-1;
		int Q;
		loop(j,1,10001)v[j].clear();
		scanf("%d",&N);
		loop(j,0,N)
		{
			int idx,a,M;
			scanf("%d",&M);
			loop(k,0,M)
			{
				scanf("%d",&a);
				maks=max(maks,a);
				if(k==0)idx=a;
				else
				{
					v[idx].pb(mp(a,1));
					v[a].pb(mp(idx,1));
					idx=a;
				}
			}
		}
		int g,h;
		scanf("%d",&Q);
		vi ans;
		vi bfs;
		loop(j,0,Q)
		{
			bool cek=0;
			bfs.assign(maks+1,-1);
			scanf("%d %d",&g,&h);
			if(sz(v[g])==0||sz(v[h])==0)ans.pb(-1);
			else
			{
				queue<ii> pq;
				pq.push(mp(0,g));
				while(!pq.empty())
				{
					ii z=pq.front();
					pq.pop();
					loop(k,0,sz(v[z.se]))
					{
						if(bfs[v[z.se][k].fi]==-1)
						{
							bfs[v[z.se][k].fi]=1;
							pq.push(mp(z.fi+1,v[z.se][k].fi));
						}
					}
					if(z.se==h)
					{
						ans.pb(z.fi);cek=1;break;	
					}
				}	
				if(!cek)ans.pb(-1);
			}
		}
		printf("Case #%d:\n",i);
		loop(j,0,sz(ans))cout<<ans[j]<<endl;
		ans.clear();
	}
}