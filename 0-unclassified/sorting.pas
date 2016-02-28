uses math;

var
	a : array [1..1000] of integer;
	i,j,temp : integer;
	
begin
	for i:=1 to 20 do begin
		a[i] := 20-i;
		write(a[i],' ');
	end; writeln;
	
	//bubble sort
	for i:=19 downto 1 do begin
		for j:=1 to i do begin
			if(a[j] > a[j+1]) then begin
				temp := a[j+1];
				a[j+1] := a[j];
				a[j] := temp;
			end;
		end;
	end;
	
	//display
	for i:=1 to 20 do write(a[i],' '); writeln;
end.