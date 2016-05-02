// 268 B

var
	a : string;
	n,t,i,j : integer;
	
begin
	readln(n,t); readln(a);
	for i:=1 to t do
	begin
		j := 1;
		while (j <= n) do
			if (a[j] = 'B') and (a[j+1] = 'G') then
			begin
				delete(a,j,1);
				insert('B',a,j+1);
				j := j + 2;
			end else inc(j);
	end;
	writeln(a);
end.