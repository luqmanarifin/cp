Program TigaTujuhTigaB;

var
	w,m,k,c : int64;
	i,digit : longint;
	temp : string;
	
function pangkat(a,b : int64): int64;
var
	temp : real;
begin
	temp := exp(b * ln(a));
	pangkat := trunc(temp);
end;
		
begin
	readln(w,m,k); c:= 0;
	str(m,temp);
	digit := length(temp);
	for i:=digit to 19 do
	begin
		if((i=digit)and(w div (k*i) <= pangkat(10,i)-m)) then
		begin
			writeln(w div (k*i)); 
			halt(0);
		end else if ((i=digit) and(w div (k*i)> pangkat(10,i)-m)) then
		begin
			c := (pangkat(10,digit)-m);
			w := w - c*k*digit;
		end else if (w > (pangkat(10,i-1)*9*k*i)) then
		begin
			c := c + pangkat(10,i-1)*9;
			w := w - pangkat(10,i-1)*9*k*i;
		end else if (w <= (pangkat(10,i-1)*9*k*i)) then
		begin
			c := c + w div (i*k);
			writeln(c); halt(0);			
		end;
	end;
end.