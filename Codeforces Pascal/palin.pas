Program PelindromeCok;

var
	a,b,hasil : string;
	i : longint;
	
begin
	readln(a);
	for i:=1 to length(a) do
	begin
		insert(a[i],b,1);
	end; writeln(b);
	for i:=1 to length(a) do
	begin
		if(pos(a[1],b) = length(b)) then
		begin
			delete(a,pos(1,a),1);
			delete(b,length[b],1);
		end else
		begin
			insert(a[1])
end.