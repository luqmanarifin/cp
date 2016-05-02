// C
var
	a : ansistring;
	n,i,j,ans : longint;
	x,null : array[1..100000] of longint;
begin
	readln(a);
	n := length(a);
	i := 1;
	j := 1;
	repeat
		val(a[i],x[j]);
		inc(i);
		while(i<=n) and(a[i]='0')do begin
			inc(null[j]);
			inc(i);
		end;
		inc(j);
	until (i>n);
	dec(j);
	n := n-null[j]-1;
	ans := 1;

	while(n > null[j]+1)or ((n = null[j]+1)and (x[1] >= x[j]))do begin
		dec(j);
		n := n-null[j]-1;
		inc(ans);
	end;
	writeln(ans);
end.