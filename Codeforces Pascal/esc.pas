Program DuaEnamLimaC;

var
	a : string;
	n,i : longint; 
	
begin
	readln(a); 
	n := length(a);
	for i:=1 to n do
	begin
		if(a[i]='r') then writeln(i);
	end;
	for i:=n downto 1 do
	begin
		if(a[i]='l') then writeln(i);
	end;
end.