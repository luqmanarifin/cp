var
	n : integer;
begin
	while not eof do begin
		read(n);
		if(n mod 2 = 1) then begin
			writeln(0);
			halt;
		end;
	end;
	writeln(1);
end.