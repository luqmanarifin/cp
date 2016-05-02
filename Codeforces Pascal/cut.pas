var
	a,b,c,n,ans : integer;
	
procedure dfs(pos, path : integer);
begin
	if(n < pos) then exit;
	dfs(pos+a, path+1);
	dfs(pos+b, path+1);
	dfs(pos+c, path+1);
	if(n = pos) and (path > ans) then ans := path;
end;

begin
	readln(n,a,b,c);
	ans := 0;
	dfs(0,0);
	writeln(ans);
end.