// 389 A
var
	n,i,j : integer;
	boo : boolean;
	x : array[1..100]of integer;
begin
	readln(n);
	for i:=1 to n do read(x[i]);
	for i:=100 downto 1 do begin
		boo := true;
		for j:=1 to n do
			if(x[j] mod i<>0) then boo := false;
		if(boo) then break;
	end;
	writeln(n*i);
end.