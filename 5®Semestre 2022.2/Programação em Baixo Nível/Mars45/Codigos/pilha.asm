.text
###################################################
# Int exemplo_folha (int g, int h, int i, int j)
# {
# Int f;
# f = (g+h) – (i + j);
# return f;
# }
###################################################

#valores imediatos
li $a0, 7   #g = a0 = 7
li $a1, 3   #h = a1 = 3
li $a2, 5   #i = a2 = 5
li $a3, 2   #j = a3 = 2

jal exemplo_folha #chamada da funcao

move $a0, $v0 #move o valor $v0 para $a0

#impressao do resultado
li $v0, 1
syscall

#finaliza o programa
li $v0, 10
syscall

#funcao
exemplo_folha:

addi $sp, $sp, -4 #desempilhamos o topo da pilha
sw $s0, 0 ($sp)  #associaremos f a s0, assim salvaremos seu valor anterior

add $t0, $a0, $a1   #soma a0 e a1 e resultado colocado no t0 (g + h)
add $t1, $a2, $a3   #soma a2 e a3 e resultado colocado no t1 (i + j)
sub $s0, $t0, $t1  #subtracao t0 e t1 e resultado colocado no s0 (g + h) - (i + j)
move $v0, $s0  #move o valor s0 para v0

lw $s0, 0 ($sp)  #retornaremos seu valor antigo a s0
addi $sp, $sp, 4  #restauremos o topo da pilha
jr $ra  #voltamos à instrucao anterior da chamada exemplo_folha.
