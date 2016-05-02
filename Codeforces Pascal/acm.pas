const X = 1000000007;
var
	n, k, l, ans : int64;
	i, j : longint;
	dp : array[1..2005]of array[1..2005] of int64;
begin
	readln(n,k);
	
	for i:=1 to 2000 do 
		for j:=1 to 2000 do
			dp[i][j] := 0;
			
	for i:=1 to 2000 do
		dp[i][1] := 1;
		
	for i:=2 to k do begin
		for j:=1 to n do begin
			l := j;
			while(l <= n) do begin
				dp[l][i] := dp[l][i] + dp[j][i-1];
				if(dp[l][i] > X) then
					dp[l][i] := dp[l][i] - X;
				l := l + j;
			end;
		end;
	end;
	
	ans := 0;
	for i:=1 to n do begin
		ans := ans + dp[i][k];
		if(ans > X) then
			ans := ans - X;
	end;
	writeln(ans);
end.