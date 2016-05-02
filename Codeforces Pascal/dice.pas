// contest A

var
	a,b,c,d,e,i : integer;
	
begin
	readln(a,b);
	c := 0; d := 0; e := 0;
	for i:=1 to 6 do
	begin
		if abs(a - i) < abs(b - i) then inc(c);
		if abs(a - i) = abs(b - i) then inc(d);
		if abs(a - i) > abs(b - i) then inc(e);
	end;
	writeln(c,' ',d,' ',e);
end.