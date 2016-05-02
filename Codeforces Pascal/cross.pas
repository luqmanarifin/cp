// 389 B
var
	n,i,j : integer;
	temp : string;
	a : array[0..101] of array[0..101] of boolean;
begin
	readln(n);
	for i:=0 to 101 do
		for j:=0 to 101 do
			a[i][j]:=true;
	for i:=1 to n do begin
		readln(temp);
		for j:=1 to n do
			if(temp[j]='#')then a[i][j]:= false;
	end;
	for i:=1 to n do
		for j:=1 to n do
			if(a[i][j]=false)and(a[i+1][j]=false)and(a[i-1][j]=false)and(a[i][j+1]=false)and(a[i][j-1]=false) then begin
				a[i][j]:=true; a[i+1][j]:=true; a[i-1][j]:=true; a[i][j+1]:=true; a[i][j-1]:=true;
			end;
	for i:=1 to n do
		for j:=1 to n do
			if(a[i][j]=false) then begin
				writeln('NO'); halt;
			end;
	writeln('YES');
end.