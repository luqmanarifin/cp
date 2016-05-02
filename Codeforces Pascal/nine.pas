Program COntest;

var
	s : string;
	i,g,n : longint;
	sum : int64;

procedure sub(s : string; var i,g,n : longint; var sum : int64);
var
	a,b,j,m : longint;
	cek : boolean;
begin
	cek := true;
	val(s[i],a); val(s[i+1],b); j := i + 2;
	g := 0;
	if (a + b = 9) then
	begin
		g := 2;
		repeat
			val(s[j],m);
			if (((j - i) mod 2 = 0) and (m = a)) then g := g + 1
			else if (((j - i) mod 2 = 1) and (m = b)) then g := g + 1
			else if (((j - i) mod 2 = 0) and (m <> a)) then cek := false
			else if (((j - i) mod 2 = 1) and (m <> b)) then cek := false;
			if (j = n) then break;
			j := j + 1;
		until not(cek);
	end;
	if(g mod 2 = 1) then sum := sum * (g + 1) div 2;
	if(g > 1) then i := i + g
	else i := i + 1;
end;

begin
	readln(s);
	n := length(s); i:=1; sum := 1;
	while (i <= n) do sub(s,i,g,n,sum);
	writeln(sum);
end.