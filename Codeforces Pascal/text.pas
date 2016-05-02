Program TigaLimaDelapanB;

var
	n	 : longint;
	a,x,b	: ansistring;
	cek : boolean;
	
procedure make(n : longint; var x,a : ansistring);
var
	i : longint;
begin
	for i:=1 to n do
	begin
		readln(x);
		insert('<3'+x,a,length(a)+1);
		if i=n then insert('<3',a,length(a)+1);
	end;
end;

procedure checking(a : ansistring; var b : ansistring; var cek : boolean);
var
	i : longint;
begin
	for i:=1 to length(a) do
	begin
		if(pos(a[i],b) = 0) then
		begin
			cek :=false;
			break;
		end else delete(b,pos(a[i],b),1);
	end;
end;

begin
	readln(n); cek := true; a := '';
	make(n,x,a);
	readln(b);
	checking(a,b,cek);
	if cek then writeln('yes')
	else writeln('no');
end.