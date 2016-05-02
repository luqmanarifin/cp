// 388 A
var
	i,n,j,temp: integer;
	x,ans : array[0..101] of integer;
begin
	readln(n);
	for i:=0 to 100 do begin x[i]:=0; ans[i]:=0; end;
	for i:=1 to n do begin
		read(temp);
		inc(x[temp]);
	end;
	for i:=0 to 100 do begin
		j:=0;
		repeat
			inc(j);
			if(x[i] > 0) then begin
				repeat
					dec(x[i]);
					inc(ans[j]);
				until(ans[j]>i)or(x[i]=0);
			end;
		until(x[i] = 0);
	end;
	for i:=1 to 101 do 
		if(ans[i]=0) then break;
	writeln(i-1);
end.