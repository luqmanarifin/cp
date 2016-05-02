// 379 C
uses math;
var
	n,i,j : longint;
	a,b,isi : array[0..299999] of longint;
	
procedure swap(var a,b : longint);
var
	temp : longint;
begin
	temp := a;
	a := b;
	b := temp;
end;

procedure Quick
    ( var b : array of longint (* in out - list to be sorted *) ;
			a : array of longint										 ;
         First : longint (* in - first item in sublist *) ;
         Last : longint (* in - last item in sublist *) ) ;
 
 var
     Pivot : longint ;
     i : longint ;
     j : longint ;

    begin (* procedure *)
         if First>=Last then begin
             (* do nothing it is sorted *)
         end else begin
              i := First ;
              J := Last + 1 ;
              Pivot := a[First] ;

              repeat
                  repeat
                    i := i + 1;
                  until a[i] >= Pivot ;
                  repeat
                    j := j - 1;
                  until a[j] <=Pivot ;
                  if i < j then begin
                     Swap (b[i], b[j]) ;
							swap (a[i], a[j]) ;
                  end ;
              until i>=j ;
					swap (a[first], a[j]);
              Swap (b[First],b[j]);
              Quick(b,a, First, j - 1);
              Quick(b,a, j+1, Last) ;
         end  (* if *) ;
    end  (* Quick *) ; 

begin
	readln(n);
	for i:=0 to n-1 do
	begin
		read(a[i]);
		isi[i] := a[i];
		b[i] := i;
	end;
	{// BUBBLE SORT
	for i:=n-2 downto 0 do
		for j:=0 to i do
			if (a[b[j]] > a[b[j+1]]) then
				swap(b[j],b[j+1]); }
	
	quick(b,isi,0,n-1);
	
	for i:=1 to n-1 do
	begin
		j := i - 1;
		while(a[b[j]] > a[b[i]]) and (j >= 0) do dec(j);
		if(a[b[j]] = a[b[i]])then a[b[i]] := a[b[i]] + i - j;
	end;
			
	for i:=0 to n-1 do write(a[i],' '); writeln;
end.