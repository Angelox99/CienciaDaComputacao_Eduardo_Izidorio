.data
	msg: .asciiz "Digite um número: "
	maior: .asciiz "O número é maior"
	menor: .asciiz "O número é menor"
	igual: .asciiz "O número é igual"
	
.text
	#imprimindo msg para o usuário
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 5
	la $a0, msg
	syscall
	
	move $t1, $v0
	
	#Se o número de entrada for par, o programa...
	beq $t1, $zero, imprimeigual
	blt $t1, $zero, imprimemenor
	bgt $t1, $zero, imprimemaior
	
	imprimeigual:
	li $v0, 4
	la $a0, igual
	syscall
	
	li $v0, 10
	syscall
	
	imprimemenor:
	li $v0, 4
	la $a0, menor
	syscall
	
	li $v0, 10 #Finaliza o programa
	syscall

	imprimemaior:
	li $v0, 4
	la $a0, maior
	syscall
	
	li $v0, 10
	syscall
	
