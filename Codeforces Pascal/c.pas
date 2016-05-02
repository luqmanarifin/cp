procedure IsFibo(x:int64);
var
	IsValid : boolean;
	k,fibo,temp : int64;
begin
	IsValid:=false;
	k:=0;
	fibo:=1;
	while (fibo<x) and (not(IsValid)) do
	begin
		writeln(k,' ',temp,' ',fibo);
		temp:=k;
		k:=fibo;
		fibo:=fibo+temp;
		if x=fibo then IsValid:=true;
	end;
	if IsValid then writeln('IsFibo') else writeln ('IsNotFibo');
end;

var 
	i,n: longint;
	T : array [1..100000] of int64;

begin
	readln(n); 
	for i:=1 to n do readln(T[i]);
	for i:=1 to n do IsFibo(T[i]);
end.