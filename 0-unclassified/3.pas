Program working_out;
uses math;
type
	tabel = array[0..1005] of array[0.1005] of longint;

var
	m, n, i, j : longint;
	asal, a, b, c, d : tabel;
	ans, cur, cuh : int64;
	
procedure generate;
begin
	for i:=0 to n-1 do 
		for j:=0 to m-1 do
			a[i][j] := max(a[i][j-1], a[i-1][j]) + asal[i][j];
			
	for i:=0 to n-1 do
		for j:=m-1 downto 0 do
			b[i][j] = max(b[i-1][j], b[i][j+1]) + asal[i][j];
			
	for i:=n-1 downto 0 do
		for j:=0 to m-1 do
			c[i][j] = max(c[i+1][j], c[i][j-1]) + asal[i][j];
			
	for i:=n-1 downto 0 do
		for j:=m-1 downto 0 do
			d[i][j] = max(d[i][j+1], d[i+1][j]) + asal[i][j];
end;
	
begin
	ans := 0;
	read(n, m);
	for i:=0 to n-1 do
		for j:=0 to m-1 do
			read(asal[i][j]);
	generate;
	
	for i:=1 to n-2 do
		for j:=1 to m-2 do begin
			cur := a[i-1][j] + d[i+1][j] + b[i][j+1] + c[i][j-1];
			cuh := a[i][j-1] + d[i][j+1] + b[i-1][j] + c[i+1][j];
			if(cur > ans) ans := cur;
			if(cuh > ans) ans := cuh;
		end;
		
	writeln(ans);
end.