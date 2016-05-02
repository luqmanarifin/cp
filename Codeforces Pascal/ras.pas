// 385 A

var
	n,c,i : integer;
	ans : longint;
	x : array[1..100] of integer;
	
begin
	ans := 0;
	readln(n,c);
	for i:=1 to n do
	begin
		read(x[i]);
		if(i > 1) and (x[i-1]-x[i]-c > ans)then ans := x[i-1]-x[i]-c;
	end;
	writeln(ans);
end.