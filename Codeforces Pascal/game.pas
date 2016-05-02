Program DuaTujuhEnamB;

var
	s : string;
	i,n,count : integer;
	x : array['a'..'z'] of integer;
	q : char;
	cek : boolean;
	
begin
	readln(s); n:= length(s); count := 0; cek := true;
	for q:='a' to 'z' do x[q] := 0;
	for i:=1 to n do
	begin
		x[s[i]] := x[s[i]] + 1;
	end;
	for q:='a' to 'z' do
	begin
		if(x[q] mod 2 = 1) then
		begin
			count := count + 1;
			cek := false;
		end;
	end;
	if ((n mod 2 = 0) and cek) then writeln('First')
	else if(count mod 2 = 1) then writeln('First')
	else writeln('Second');
end.