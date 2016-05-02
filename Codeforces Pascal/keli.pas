var
	i : integer;
	n : longint;
begin
	n := 1;
	for i:=1 to 100 do begin
		n := n * 7;
		writeln(n);
	end;
end.