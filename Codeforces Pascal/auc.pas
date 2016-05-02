// 386 A

var
	i,n,maxi,max,seci : integer;
	p : array[1..1000] of integer;
	
begin
	readln(n);
	max := 0;
	for i:=1 to n do begin
		read(p[i]);
		if(p[i] > max) then begin
			max := p[i];
			maxi := i;
		end;
	end; max := 0;
	for i:=1 to n do
		if(p[maxi]+p[i] > max)and (maxi<>i) then begin
			seci := i;
			max := p[maxi]+p[i];
		end;
	writeln(maxi,' ',p[seci]);
end.