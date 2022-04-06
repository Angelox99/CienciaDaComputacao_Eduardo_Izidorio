Program Fatorial ;
var
    n,x,cont,fatorial:integer;
Begin
	readln(n);
	fatorial:=1;
	cont:=1;
	repeat
		fatorial:= fatorial*cont;
		cont:=cont+1
	until (cont>n);
	writeln('O valor de' ,n, '!:',fatorial);
	  
End.