// A
var
	s,t,temp : string;
	secs, sect,secans,jam,menit,a,b : longint;
begin
	readln(s);
	readln(t);
	temp := s;
	
	delete(temp,3,3);
	delete(s,1,3);
	val(temp,a); val(s,b);
	secs := a*60 + b;
	
	temp := t;
	delete(temp,3,3);
	delete(t,1,3);
	val(temp,a); val(t,b);
	sect := a*60 + b;
	
	secans := secs - sect;
	if(secans < 0) then secans := secans + 24*60;
	jam := secans div 60;
	if jam < 10 then write('0');
	write(jam,':');
	menit := secans mod 60;
	if(menit < 10) then write(0);
	write(menit);
end.