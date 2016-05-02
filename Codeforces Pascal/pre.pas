// C

const maxn = 60000000;
var
	m,n,i,sum,a,x,l,c,j,k : longint;
	s : array[1..maxn] of longint;
	
begin
	readln(m); sum := 0;
	for i:=1 to m do 
	begin
		read(a);
		case a of 
		1 : begin
				readln(x);
				s[sum+1] := x;
				sum := sum + 1;
				end;
		2 : begin
				readln(l,c);
				for j:=1 to c do
				begin
					if (sum + l > maxn) then break;
					for k :=1 to l do
						s[sum+k] := s[k];
					sum := sum + l;
				end;
			end;
		end;
	end;
	readln(n);
	for i:=1 to n do
	begin
		read(a);
		write(s[a], ' ');
	end;
end.
				