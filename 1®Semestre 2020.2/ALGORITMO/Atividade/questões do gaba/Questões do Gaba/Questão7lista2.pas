Program ExemploPzim ;
Var anterior1, anterior2, proximo: integer ;
    i: integer ;
    N: integer;
 Begin
 	N:=10;
 	
	// Imprime primeiros dois elementos da s�rie
 	anterior1:=1;
 	anterior2:=1;
 	write('1 1');
 	
 	// C�lculo da s�rie  	
 	i:=3;  	
	while ( i <= N ) do begin
   		proximo:= anterior1 + anterior2;
     	write(' ', proximo);
     	anterior2:= anterior1;
     	anterior1:= proximo;  
     	i:= i+1;
	end;
 End.          
