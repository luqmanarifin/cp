var s:ansistring;
    n,z:array [1..100000] of longint;
    i,j,size,ans:longint;

begin
	read(s);
	size:=length(s);
	s:=s+'9';
	i:=1;
	j:=1;
	repeat
		val(s[i],n[j]);
		inc(i);
		while (s[i]='0') and (i<=size) do
		begin
			inc(i);
			inc(z[j]);
		end;
		inc(j);
	until i>size;
	dec(j);
	size:=size-z[j]-1;
	ans:=1;
	while (size>z[j]+1) or ((size=z[j]+1) and (n[1]>=n[j])) do
	begin
		dec(j);
		size:=size-z[j]-1;
		inc(ans);
	end;

	write(ans);
end.