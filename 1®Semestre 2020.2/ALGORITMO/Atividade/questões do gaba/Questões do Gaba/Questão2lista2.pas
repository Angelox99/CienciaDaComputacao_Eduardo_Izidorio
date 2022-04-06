Program Impar ;
var 
	num:integer;
Begin
	num:=2;
	while (num<16) do
		begin
		if ((num)mod(2) <> 0) then
			writeln(num);
			num:= num+1;
		end  
End.