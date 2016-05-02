// 158C

var
	a,s,temp,balik : string;
	n,i,k : integer;
	
procedure iuh(a : string; var balik : string);
var
	n,i : longint;
begin
	n := length(a);
	for i:=1 to n do insert(a[i],balik,1);
	delete(balik,1,1);
end;
	
begin
	readln(n);
	s := '/';
	for i:=1 to n do
	begin
		readln(a); k:= 0;
		if(a = 'pwd') then writeln(s)
		else if (a = 'cd ..') and (s = '/') then s := '/'
		else begin
			while(pos('..',a) <> 0) do
			begin
				if (pos('..',a) = 4) then
				begin
					iuh(s,balik);
					delete(s,length(s)-pos('/',balik)+1,pos('/',balik));
					delete(a,4,2);
				end else begin
					temp := a;
					delete(temp,pos('..',temp),length(temp)-pos('..',temp)+1);
					delete(temp,1,3);
					if (temp = '/') then iuh(s,balik)
					else if(temp[1] = '/') and (k=0) then s := temp
					else begin
						if(temp[1] = '/') then delete(temp,1,1);
						insert(temp,s,length(s)+1);
					end;
					delete(a,4,length(temp));
					if(s[length(s)] <> '/') then insert('/',s,length(s)+1);
				end;
				inc(k);
			end;
			if (k=0) then
			begin
				if(length(a) > 3) then
				begin
					delete(a,1,3);
					if(a[1] = '/') then s := a
					else insert(a,s,length(s)+1);
					if(s[length(s)] <> '/') then insert('/',s,length(s)+1);
				end;
			end else begin
				if(length(a) > 3) then
				begin
					delete(a,1,3);
					if(a[1] = '/') then delete(a,1,1);
					insert(a,s,length(s)+1);
					if(s[length(s)] <> '/') then insert('/',s,length(s)+1);
				end;
			end;
		end;
	end;
end.