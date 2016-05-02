Program TigaEnamTigaA;

var
	n,i	: longint;

begin
	readln(n);
	if (n=0) then writeln('O-|-OOOO');
	for i:=1 to 9 do
	begin
		if((n div 10 <> 0) and (n mod 10 = 0)) then writeln('O-|-OOOO');
		case(n mod 10) of
		1 : writeln('O-|O-OOO');
		2 : writeln('O-|OO-OO');
		3 : writeln('O-|OOO-O');
		4 : writeln('O-|OOOO-');
		5 : writeln('-O|-OOOO');
		6 : writeln('-O|O-OOO');
		7 : writeln('-O|OO-OO');
		8 : writeln('-O|OOO-O');
		9 : writeln('-O|OOOO-');
		end;
		n := n div 10;
	end;
end.
		