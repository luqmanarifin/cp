Program Asu;

var
	y : array[1..9] of longint;
	n,i : integer; a,b,c,d : string; cek : boolean;

procedure Masuk(a : string; var x : array of longint);
var
	i : integer;
begin
	for i:=1 to 4 do
	begin
		case (a[i]) of 
		'1'	: x[1] := x[1] + 1;
		'2'	: x[2] := x[2] + 1;
		'3'	: x[3] := x[3] + 1;
		'4'	: x[4] := x[4] + 1;
		'5'	: x[5] := x[5] + 1;
		'6'	: x[6] := x[6] + 1;
		'7'	: x[7] := x[7] + 1;
		'8'	: x[8] := x[8] + 1;
		'9'	: x[9] := x[9] + 1;
		end;
	end;
end;
	
begin
	cek := true;
	readln(n); readln(a); readln(b); readln(c); readln(d);
	for i:=2 to 10 do y[i] := 0;
	Masuk(a,y); Masuk(b,y); Masuk(c,y); Masuk(d,y);
	for i:=2 to 10 do 
	begin
		if (y[i] > 2*n) then cek := false;
	end;
	if (cek) then writeln('YES')
	else writeln('NO');
end.