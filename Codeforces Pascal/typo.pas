Program TigaEnamTigaC;

var
	a : ansistring;
	i : longint;
begin
	readln(a);
	for i:=length(a) downto 1 do
	begin
		if ((a[i] = a[i+1]) and (a[i+2] = a[i+3]) and (a[i-1] = a[i-2]) and (i + 2 <= length(a))) then delete(a,i,1)
		else if ((a[i] = a[i+1]) and (a[i+1]=a[i+2])) then delete(a,i,1)
		else if ((a[i] = a[i+1]) and (a[i+2]=a[i+3]) and (i + 2 <= length(a))) then delete(a,i,1);
	end;
	writeln(a);
end.