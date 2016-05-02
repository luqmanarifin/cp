// 71 A

var
	a : string;
	n,i : integer;
	
begin
	readln(n);
	for i:=1 to n do
	begin
		readln(a);
		if(length(a) > 10) then writeln(a[1],length(a)-2,a[length(a)])
		else writeln(a);
	end;
end.