Program DuaKosongA;

var
	s,b : string;
	i,n : integer;
	
begin
	readln(s);
	n := length(s);
	for i:=1 to n do insert('/',b,1);
	i := n;
	if (s=b) then
	begin
		writeln('/');
		halt(0);
	end else begin
		while(s[i] = '/') do
		begin
			delete(s,i,1);
			i := i - 1;
		end;
	end;
	for i:=n downto 1 do
	begin
		if((s[i]='/') and (s[i+1]='/')) then delete(s,i,1);
	end;
	writeln(s);
end.
