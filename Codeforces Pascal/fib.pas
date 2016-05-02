
var
	i,n : longint;
	s,ans : string;
function hit(a : char): integer;
begin
	case a of
	'a' : hit := 1;
	'b' : hit := 2;
	'c' : hit := 3;
	'd' : hit := 4;
	'e' : hit := 5;
	'f' : hit := 6;
	'g' : hit := 7;
	'h' : hit := 8;
	'i' : hit := 9;
	'j' : hit := 10;
	'k' : hit := 11;
	'l' : hit := 12;
	'm' : hit := 13;
	'n' : hit := 14;
	'o' : hit := 15;
	'p' : hit := 16;
	'q' : hit := 17;
	'r' : hit := 18;
	's' : hit := 19;
	't' : hit := 20;
	'u' : hit := 21;
	'v' : hit := 22;
	'w' : hit := 23;
	'x' : hit := 24;
	'y' : hit := 25;
	'z' : hit := 26;
	else hit := 0;
	end;
end;
function chip(n : integer; s : char): char;
begin
	if(hit(s) = 0) then chip := s
	else 
		chip := chr((hit(s) + n) mod 26 + 64);
end;
	
begin
	readln(s);
	readln(n);
	for i:=length(s) downto 1 do
	begin
		insert(chip(n,s[i]),ans,1);
	end;
	writeln(ans);
end.