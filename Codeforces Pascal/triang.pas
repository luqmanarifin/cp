uses math;
var
	a, b, m, n, d, f, temp : int64;
	i : longint;
begin
	m := 0; n := 0; d := 0; f := 0;
	readln(a,b);
	
	if(a > b) then begin
		temp := b;
		b := a;
		a := temp;
	end;
	
	temp := floor(a/sqrt(2));
	for i:=1 to temp do 
		if(frac(sqrt(a*a - i*i)) = 0) then begin
			m := i;
			d := floor(sqrt(a*a-i*i));
			break;
		end;
		
	temp := floor(b/sqrt(2));
	for i:=1 to temp do 
		if(frac(sqrt(b*b - i*i)) = 0) then begin
			n := i;
			f := floor(sqrt(b*b-i*i));
			break;
		end;
	if(m = f) then begin
		temp := f;
		f := n;
		n := temp;
	end;
	writeln(m,' ',d,' ',n,' ',f);
	if((f-m)*(f-m) + (d+n)*(d+n) = a*a + b*b) then begin
		writeln('YES');
		writeln(d,' ',0);
		writeln(0,' ',m);
		writeln(d+n,' ',f);
	end else writeln('NO');
end.