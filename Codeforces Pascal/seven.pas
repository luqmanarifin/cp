// C

var
	a : string;
	permut : array[0..6]of string;
	temp : integer;
	digit : array[0..9] of longint;
	i,j : longint;
	
procedure masuk(a : string; var digit : array of longint);
var
	i : longint;
	n : longint;
begin
	n := length(a);
	for i:=0 to 9 do digit[i] := 0;
	for i:=1 to n do
	begin
		case a[i] of
		'0' : inc(digit[0]);
		'1' : inc(digit[1]);
		'2' : inc(digit[2]);
		'3' : inc(digit[3]);
		'4' : inc(digit[4]);
		'5' : inc(digit[5]);
		'6' : inc(digit[6]);
		'7' : inc(digit[7]);
		'8' : inc(digit[8]);
		'9' : inc(digit[9]);
		end;
	end;
	dec(digit[1]); dec(digit[8]); dec(digit[6]); dec(digit[9]);
end;
	
begin
	permut[0] := '1869';
	permut[1] := '6198';
	permut[2] := '1896';
	permut[3] := '9186';
	permut[4] := '9168';
	permut[5] := '6189';
	permut[6] := '8691';
	readln(a);
	masuk(a, digit);
	temp := 0;
	for i:=1 to 9 do
	begin
		for j:=1 to digit[i] do
		begin
			write(i);
			temp := (temp*10 + i) mod 7;
		end;
	end;
	write(permut[temp]);
	for i:=1 to digit[0] do write('0');
	writeln;
end.