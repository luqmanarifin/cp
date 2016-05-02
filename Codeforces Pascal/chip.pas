Program Juancok;
var
	n,m,total,i : longint;

begin
	readln(n,m);
	total := (n*(n+1)) div 2;
	m := m mod total;
	for i:=1 to n do
	begin
		if(m >= i) then m := m - i
		else
		begin
			writeln(m); halt(0);
		end;
	end;
end.