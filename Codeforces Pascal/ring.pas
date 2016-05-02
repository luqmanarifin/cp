// 339 B

var
	n, m, i : longint;
	ans : int64;
	a : array[0..100000] of longint;
	
begin
	readln(n,m);
	a[0] := 1;
	ans := 0;
	for i:=1 to m do
	begin
		read(a[i]);
		if (a[i] < a[i-1]) then ans := ans + a[i] + n - a[i-1]
		else ans := ans + a[i] - a[i-1];
	end;
	writeln(ans);
end.