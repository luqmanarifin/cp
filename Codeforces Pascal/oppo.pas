Program opposeh;

var
	x : array[-10..10] of int64;
	n,count,a : int64; i: longint;
	
begin
	readln(n); count := 0;
	for i:=-10 to 10 do x[i] := 0;
	for i:=1 to n do
	begin
		read(a);
		inc(x[a]);
	end;
	for i:=1 to 10 do
	begin
		count := count + (x[i]*x[-i]);
	end;
	count := count + (x[0]*(x[0]-1)) div 2;
	writeln(count);
end.