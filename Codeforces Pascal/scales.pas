//382 A

var
	a,b,temp : string;
	kanan,kiri : longint;
	
function min(a,b : longint): longint;
begin
	if(a > b) then min := b
	else min := a;
end;

function max(a,b : longint) : longint;
begin
	if(a > b) then max := a
	else max := b;
end;
	
begin
	readln(a); readln(b);
	kiri := pos('|',a) - 1;
	kanan := length(a) - pos('|',a);
	if((length(a)-1+ length(b)) mod 2 = 1) then begin
		writeln('Impossible');
		halt(0);
	end else if(min(kanan,kiri) + length(b) < max(kanan,kiri)) then begin
		writeln('Impossible');
		halt(0);
	end else if(kiri < kanan) then begin
		temp := b;
		delete(temp,kanan-kiri+1,length(temp)-kanan+kiri);
		delete(b,1,kanan-kiri);
		insert(temp,a,1);
	end else begin
		temp := b;
		delete(temp,kiri-kanan+1,length(temp)-kiri+kanan);
		delete(b,1,kiri-kanan);
		insert(temp,a,length(a)+1);
	end;
	temp := b;
	delete(temp,length(temp) div 2 + 1,length(temp) div 2);
	delete(b,1,length(b) div 2);
	insert(temp,a,1);
	insert(b,a,length(a)+1);
	writeln(a);
end.	