Program GoodNumber;

var
	a: int64; p,n,k,i,j,temp,count : integer; cek : boolean;
	x : array[0..9] of integer; kata : string;
	
begin
	readln(n,k); count := 0;
	for i:=1 to n do
	begin
		readln(a); cek := true;
		str(a,kata); p := length(kata);
		for j:=0 to k do x[j] := 0;
		for j:=1 to p do
		begin
			temp := a mod 10;
			inc(x[temp]);
			a := a div 10;
		end;
		for j:=0 to k do
			if(x[j] = 0) then cek := false;
		if (cek) then count := count + 1;
	end;
	writeln(count);
end.