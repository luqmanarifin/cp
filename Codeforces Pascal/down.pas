Program TigaTigaDuaA;

var
	n,i,count : integer; a : ansistring;
	
begin
	readln(n); readln(a); count := 0;
	i := n + 1;
	while (i <= length(a)) do
	begin
		if ((a[i-1] = a[i-2]) and (a[i-2] = a[i-3])) then count := count + 1;
		i := i + n;
	end;
	writeln(count);
end.