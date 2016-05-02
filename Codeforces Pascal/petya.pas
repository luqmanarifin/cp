// 112 A

var
	a,b : string;
	i : integer;
	
function angka(a : char): integer;
begin
	case a of
	'a' : angka := 1;
	'b' : angka := 2;
	'c' : angka := 3;
	'd' : angka := 4;
	'e' : angka := 5;
	'f' : angka := 6;
	'g' : angka := 7;
	'h' : angka := 8;
	'i' : angka := 9;
	'j' : angka := 10;
	'k' : angka := 11;
	'l' : angka := 12;
	'm' : angka := 13;
	'n' : angka := 14;
	'o' : angka := 15;
	'p' : angka := 16;
	'q' : angka := 17;
	'r' : angka := 18;
	's' : angka := 19;
	't' : angka := 20;
	'u' : angka := 21;
	'v' : angka := 22;
	'w' : angka := 23;
	'x' : angka := 24;
	'y' : angka := 25;
	'z' : angka := 26;
	end;
end;
	
begin
	readln(a); readln(b);
	a := lowercase(a); b := lowercase(b);
	for i:=1 to length(a) do
	begin
		if (angka(a[i]) < angka(b[i])) then
		begin
			writeln(-1);
			halt(0);
		end;
		if (angka(a[i]) > angka(b[i])) then
		begin
			writeln(1);
			halt(0);
		end;
	end;
	writeln(0);
end.