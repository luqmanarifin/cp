var output : textfile;

begin
	assign(output,'test.out');
	rewrite(output);
	writeln(output, 'asu');
	close(output);
end.