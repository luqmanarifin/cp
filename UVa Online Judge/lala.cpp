#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n,m,k,pager;
char chr[505][505];
int titik[505][505];
#define oke(a,b) a>=0&&a<n&&b>=0&&b<m

int main(){
	cin>>n>>m>>k;
	pager=k;
	for (int i = 0; i < n; ++i)
	{
		cin>>chr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(chr[i][j]!='#'){
				if(chr[i-1][j]=='.' && oke(i-1,j)) titik[i][j]++;
				if(chr[i+1][j]=='.' && oke(i+1,j)) titik[i][j]++;
				if(chr[i][j+1]=='.' && oke(i,j+1)) titik[i][j]++;
				if(chr[i][j-1]=='.' && oke(i,j-1)) titik[i][j]++;
			}
		}
	}
	priority_queue<tuple<int,int,int>> pq;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			pq.push(make_tuple(-titik[i][j],i,j));
		}
	}
	while(!pq.empty()){
		int i,j,byk;
		tie(byk,i,j)=pq.top();
		pq.pop();
		if(chr[i][j]!='#' && chr[i][j]!='X' && pager>0){
			chr[i][j]='X';
			pager--;
			//cout<<i<<" "<<j<<endl;
			if(oke(i+1,j) && chr[i+1][j]!='#'){titik[i+1][j]--;pq.push(make_tuple(-titik[i+1][j],i+1,j));}
			if(oke(i-1,j) && chr[i-1][j]!='#'){titik[i-1][j]--;pq.push(make_tuple(-titik[i-1][j],i-1,j));}
			if(oke(i,j+1) && chr[i][j+1]!='#'){titik[i][j+1]--;pq.push(make_tuple(-titik[i][j+1],i,j+1));}
			if(oke(i,j-1) && chr[i][j-1]!='#'){titik[i][j-1]--;pq.push(make_tuple(-titik[i][j-1],i,j-1));}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<chr[i][j];
		}
		cout<<endl;
	}
}