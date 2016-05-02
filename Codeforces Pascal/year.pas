Program BeautifulYear;

var
	n,i,a,b,c,d : longint; cek : boolean;

begin
	readln(n); i:= n + 1; cek:= false;
	while((i <= 9013) and not(cek)) do
	begin
		a := i mod 10;
		b := (i div 10) mod 10;
		c := (i div 100) mod 10;
		d := (i div 1000) mod 10;
		if((a<>b) and (a<>c) and (a<>d) and (b<>c) and (b<>d) and(c<>d)) then cek := true
		else i := i + 1;
	end;
	writeln(i);
end.