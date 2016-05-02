Program p476;

var
	x, i, jawab : int64;
	cek : boolean;

begin
	for i:=1 to x do
	begin
		if(not(cek) and (i*(i + 1)/2 > x)) then
		begin
			jawab := i;
			cek := true;
		end;
	end;
	writeln(jawab);
end.
		