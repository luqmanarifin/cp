Program BoyOrGirl;

var
	a : string;
	c : char; letak, count : integer;

begin
	readln(a); count := 0;
	for c:='a' to 'z' do
	begin
		letak := pos(c,a); if(letak <> 0) then count := count + 1;
	end;
	if (count mod 2 = 0) then writeln('CHAT WITH HER!')
	else writeln('IGNORE HIM!')
end.
	