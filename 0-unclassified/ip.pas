var
	total : real;
	i : integer;
	idx : string;
	
function convert(indeks : string): real;
begin
	case indeks of
		'A' : convert := 4;
		'AB' : convert := 3.5;
		'B' : convert := 3;
		'BC' : convert := 2.5;
		'C' : convert := 2;
		'D' : convert := 1;
		'E' : convert := 0;
	end;
end;
	
begin
	total := 0;
	for i:=1 to 7 do begin
		write('Indeks ');
		case i of
			1 : write('Kalkulus : ');
			2 : write('Fisika : ');
			3 : write('Kimia : ');
			4 : write('PRD : ');
			5 : write('TTKI : ');
			6 : write('Daspro : ');
			7 : write('PAR : ');
		end;
		readln(idx);
		if(i <= 2) then total := total + convert(idx)*4
		else total := total + convert(idx)*2;
	end;
	writeln;
	writeln('IP anda semester ini adalah : ', (total/18):0:2);
end.