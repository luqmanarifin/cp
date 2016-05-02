Program p271;

var
	i, n, k : integer;
	
begin
	readln(n, k);
	for i:=1 to n do
	begin
		if (i mod k = 0) then write('*')
		else write(i);
		if (i <> n) then write(' ');
	end;
end.