Program MagnetsOnMagnet;

var
	n,i,count : longint;
	x : array[1..100000] of integer;

begin
	readln(n); count := 0;
	for i:=1 to n do
	begin
		readln(x[i]);
		if ((i <> 1) and (x[i] <> x[i-1])) then count := count + 1;
	end;
	writeln(count + 1);
end.