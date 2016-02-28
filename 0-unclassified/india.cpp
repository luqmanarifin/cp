#include <iostream>
#include<cmath>
#include<limits.h>
using namespace std;
 long long int A[10000007];
long long  int L[10000005];
long long  int R[10000004];
  //  long long int st[50000000];
  long long int min1(long long int a,long long int b)
  {
  	if(a>b)
  	return b;
  	else
  	return a;
  }
  int getMid(int s, int e) {  return s + (e -s)/2;  }
     //long long int *st = new long long int[max_size];
     int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return min(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
long long int p1(long long int a,long long int b,long long int n){
	long long int res=1;
	while(b){
		if(b&1){
			res=(res%n*a%n)%n;
	        res=res%n;
		}
		a=(a%n*a%n)%n;
		b=b/2;
	}
	return res;
}
 
int constructSTUtil(long long int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  min(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
int *constructST(long long int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
 
 
int main() {
    int n,k,q;
    cin>>n>>k>>q;
    long long int a, b, c, d, e, f, r, s, t, m;
 
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A[0];
    long long cuk = t % s;
    for(int x=2;x<=n;x++){
      cuk = cuk * t % s;
    	if(cuk<=r){
    		A[x-1]=((a%m*(A[x-2]%m*A[x-2]%m)%m)%m+(b%m*A[x-2]%m)%m+c%m)%m;
 
    	}
    	else{
    		A[x-1]=((d%m*(A[x-2]%m*A[x-2]%m)%m)%m+(e%m*A[x-2]%m)%m+f%m)%m;
 
    	}
    //cout<<A[x]<<endl;
    }
     int *st = constructST(A, n);
 
  int M=1000000000+7;
 long long int sum=0;
 long long int p=1;
 
 long long int L1,La,Lc,Lm,D1,Da,Dc,Dm;
 cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
 for(int i=0;i<q;i++){
 	L1=((La%Lm*L1%Lm)+Lc%Lm)%Lm;
 	D1 = (Da %Dm* D1%Dm + Dc%Dm) % Dm; 
 	L[i]=L1+1;
 	R[i] = min1(L[i] + k - 1 + D1, n);
 		long long int da=(long long int)RMQUtil(st, 0, n-1,(int)(L[i]-1), (int)(R[i]-1), 0);
 	sum=sum+da;
 	//p=M-1;
 	//da=M-1;
 	p=(p*da)%M;
 	p=p%M;
 
 }
 
 
 
 //cout<<log2(2)<<endl;
 
 
 cout<<sum<<" "<<p;
 
 // your code goes here
	return 0;
}