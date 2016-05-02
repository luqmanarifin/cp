// 383A
var
	n,i,satu,nol,one,null : longint;
	temp,tmp : int64;
	x : array[1..200000] of integer;
	
begin
	readln(n); satu := 0; nol := 0; temp := 0; tmp := 0;
	for i:=1 to n do begin
		read(x[i]);
		if(x[i]=1) then inc(satu)
		else inc(nol);
	end; one := satu; null := nol;
	for i:=1 to n do
		if(x[i]=0) then dec(null)
		else temp := temp + null;
	null := nol;
	for i:=n downto 1 do
		if(x[i]=1) then dec(one)
		else tmp := tmp + one;
	if(temp < tmp) then writeln(temp)
	else writeln(tmp);
end.