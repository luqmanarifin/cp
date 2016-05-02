Program DuaTujuhEnamA;

var
	n,i : longint;
	k,max,f,t,a : int64;
	
begin
	readln(n,k); max := -1000000000;
	for i:=1 to n do
	begin
		readln(f,t);
		if (t <= k) then a := f
		else a := f - t + k;
		if (a > max) then max := a;
	end;
	writeln(max);
end.