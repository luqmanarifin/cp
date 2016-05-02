Program CodeForces;

var
	a,b,c,n,i,count : integer;
	
begin
	readln(n); count := 0;
	for i:=1 to n do
	begin
		readln(a,b,c);
		if (a+b+c >= 2) then count := count + 1;
	end; writeln(count);
end.