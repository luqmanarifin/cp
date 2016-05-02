Program Juancok;

var
	n,k,i,count : integer;
	a : array[1..100] of integer;

begin
	readln(n,k); count := 0;
	for i:=1 to n do read(a[i]);
	for i:=1 to n do
	begin
		if((a[i] >= a[k]) and (a[i] > 0)) then count := count + 1;
	end;
	writeln(count);
end.