uses sysutils;
var
	i, t, n : integer;
	s : ansistring;
	f, r : boolean;
begin
	readln(t);
	for i:=1 to t do
	begin
		readln(s);
		n := length(s);
		f := copy(s, n-4, 5) = 'lala.';
		r := copy(s, 1, 5) = 'miao.';
		if f and r then writeln('OMG>.< I don', chr(39) ,'t know!')
		else if f then writeln('Freda', chr(39) ,'s')
		else if r then writeln('Rainbow', chr(39) ,'s')
		else writeln('OMG>.< I don',chr(39),'t know!');
	end;
end.