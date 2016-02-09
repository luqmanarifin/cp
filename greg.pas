const maxn = 100005;

var
	ans, v, op : array[0..maxn] of int64;
	lef, rig, a : array[0..maxn] of longint;
	i, n, m, k, l, r : longint;
	
begin
	read(n, m, k);
	fillchar(op, sizeof(op), 0);
	fillchar(ans, sizeof(ans), 0);
	for i:=0 to n-1 do read(a[i]);
	for i:=0 to m-1 do
	begin
		read(lef[i], rig[i], v[i]);
		dec(lef[i]);
		dec(rig[i]);
	end;
	for i:=0 to k-1 do
	begin
		read(l, r);
		inc(op[l-1]);
		dec(op[r]);
	end;
	for i:=0 to m-1 do
	begin
		if(i > 0) then inc(op[i], op[i-1]);
		inc(ans[lef[i]], v[i]*op[i]);
		dec(ans[rig[i]+1], v[i]*op[i]);
	end;
	for i:=0 to n-1 do
	begin
		if(i > 0) then inc(ans[i], ans[i-1]);
		write(ans[i] + a[i], ' ');
	end;
	writeln;
end.