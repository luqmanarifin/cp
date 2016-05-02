Program SystemEq;

var
	n, m, i, j, count : integer;

begin
	readln(n,m); count := 0;
	for i:=0 to trunc(sqrt(n)) do
	begin
		for j:=0 to trunc(sqrt(m)) do
		begin
			if((i*i + j = n) and (i + j*j = m)) then count := count + 1;
		end;
	end;
	writeln(count);
end.