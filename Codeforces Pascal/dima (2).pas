// A

var
	n : integer;
	i,j,k : integer;
	ser,dim : integer;
	card : array[1..1000] of longint;
	
begin
	readln(n);
	for i:=1 to n do read(card[i]);
	i := 1; j := n; ser := 0; dim := 0;
	for k := 1 to n do
	begin
		if(k mod 2 = 1) then
		begin
			if (card[i] > card[j]) then
			begin
				ser := ser + card[i];
				inc(i);
			end else begin
				ser := ser + card[j];
				dec(j);
			end;
		end else
			if (card[i] > card[j]) then
			begin
				dim := dim + card[i];
				inc(i);
			end else begin
				dim := dim + card[j];
				dec(j);
			end;
	end;
	writeln(ser,' ',dim);
end.
			