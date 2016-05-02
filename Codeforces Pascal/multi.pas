// 384 B

type
	myArray = array[1..100] of longint;
	matriks = array[1..1000] of myArray;
var
	m,n,i,j,k,a,b : integer;
	x : matriks;
	ans : array[1..5000] of longint;
	u : longint;
	
procedure swap(var a,b : longint);
var temp : longint;
begin
	temp := a;
	a := b;
	b := temp;
end;

procedure ascen(n,dex : integer; var a : matriks; var u : longint; var ans : array of longint);
var i,j,k : integer;
begin
	for i:=n-2 downto 0 do
		for j:=0 to i do
			if(a[dex][j]>a[dex][j+1])then begin
				for k:=dex to n-1 do
					swap(a[k][j],a[k][j+1]);
				ans[u] := j+1;
				inc(u);
			end;
end;

procedure descen(n,dex : integer; var a : matriks; var u : longint; var ans : array of longint);
var i,j,k : integer;
begin
	for i:=n-2 downto 0 do
		for j:=0 to i do
			if(a[dex][j]<a[dex][j+1])then begin
				for k:=dex to n-1 do
					swap(a[k][j],a[k][j+1]);
				ans[u] := j+1;
				inc(u);
			end;
end;
	
begin
	u := 0;
	readln(n,m,k);
	for i:=0 to n-1 do
		for j:=0 to m-1 do
			read(x[i][j]);
			
	if(k = 0) then begin
		for a:=0 to n-1 do begin
			ascen(n,a,x,u,ans);
		end;
	end else
		for a:=0 to n-1 do begin
			descen(n,a,x,u,ans);
		end;
	writeln(u);
	for i:=0 to u-1 do
		writeln(ans[i],' ',ans[i]+1);
end.