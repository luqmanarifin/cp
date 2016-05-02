// 253 B
const
	inf = 16513376;
var
	fin,fout : file of longint;
	n,i,a,min,max,atas,bawah,bawah2,bawah3 : longint;
	c : array[1..5000] of longint;
	
function oh (a,b : longint): longint;
begin
	if (a > b) then oh := b
	else oh := a;
end;

procedure take;
begin
	assign(fin,'input.txt'); reset(fin);
	assign(fout,'output.txt'); rewrite(fout);
	read(fin,n);
	for i:=1 to 5000 do c[i] := 0;
	for i:=1 to n do
	begin
		read(fin,a);
		c[a] := c[a] + 1;
	end;
	for i:=1 to 5000 do
		if(c[i] <> 0) then 
		begin
			min := i;
			break;
		end;
	for i:=5000 downto 1 do
		if(c[i] <> 0) then 
		begin
			max := i;
			break;
		end;
end;

procedure process;
begin
	atas := 0; bawah := 0; bawah2 := 0; bawah3 := c[max];
	for i:=2*min+1 to 5000 do atas := atas + c[i];
	if (max mod 2 = 0) then
	begin
		for i:=max div 2-1 downto 1 do bawah := bawah + c[i];
		bawah2 := inf; bawah3 := inf;
	end else begin
		for i:=max div 2 downto 1 do
		begin
			bawah2 := bawah2 + c[i];
			if (i <> max div 2) then bawah3 := bawah3 + c[i];
		end; bawah := inf;
	end;
	a := inf;
	a := oh(a,atas);
	a := oh(a,bawah);
	a := oh(a,bawah2);
	a := oh(a,bawah3);
	write(fout,a);
end;

begin
	take;
	process;
	close(fin); close(fout);
end.