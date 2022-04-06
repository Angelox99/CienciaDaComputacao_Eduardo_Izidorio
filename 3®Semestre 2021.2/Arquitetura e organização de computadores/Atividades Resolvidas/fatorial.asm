.text
   li $a0, 5

fatorial:
	addi $sp, $sp, 8 #colocaremos 2 itens na pilha
	sw $ra, 4 ($sp) #salvamos o endereço de retorno
	sw $a0, 0 ($sp) #salvamos o argumento n
        slt $t0, $a0, 1 #n é menor que 1?
	beq $t0, $zero, L1 #vai para L1 se (n >= 1)
	add $v0, $zero, 1 #retorna 1 se (n < 1)
	add $sp, $sp, 8 #retira dois itens da pilha
	jr $ra #retorna

L1:
   sub $a0, $a0, 1 #(n - 1) se (n >= 1)
   jal fatorial #chama fatorial novamente com o argumento decrementado

lw $a0, 0 ($sp) #restaura o argumento n
lw $ra, 4 ($sp) #restaura o endereço de retorno
addi $sp, $sp, 8 #ajusta o stack pointer - retira dois itens da pilha
mul $v0, $a0, $v0 #retorna n * fatorial (n - 1)
jr $ra #retorna para o procedimento que o chamou
