// B

var
	n,m,i,a,b,c : longint;
	duit : array[1..100] of longint;
	ans : int64;
	
begin
	readln(n,m);
	for i:=1 to 100 do duit[i] := 0;
	for i:=1 to m do
	begin
		readln(a,b,c);
		duit[b] := duit[b] + c;
		duit[a] := duit[a] - c;
	end;
	ans := 0;
	for i:=1 to n do
		if(duit[i] > 0) then ans := ans + duit[i];
	writeln(ans);
end.