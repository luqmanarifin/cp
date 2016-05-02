// 377 A
var
	n,m,k,i,j : integer;
	a : array[0..501,0..501] of char;
	
procedure dfs(x,y : integer);
begin
	if(x <= 0)or(x > n)or(y <= 0)or(y > m)or(a[x,y] <> '.') then exit;
	a[x,y] := 'L';
	dfs(x,y+1);
	dfs(x,y-1);
	dfs(x+1,y);
	dfs(x-1,y);
	if k = 0 then exit;
	a[x,y] := 'X';
	dec(k);
end;

begin
	readln(n,m,k);
	for i:=1 to n do begin
		for j:=1 to m do
			read(a[i,j]);
		readln;
	end;
	for i:=1 to n do
		for j:=1 to m do
			if(a[i,j] = '.') then dfs(i,j);
	for i:=1 to n do begin
		for j:=1 to m do
			if(a[i,j] = 'L') then write('.')
			else write(a[i,j]);
		writeln;
	end;
end.