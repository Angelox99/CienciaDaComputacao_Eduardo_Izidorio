.data
msg1: .asciiz "Digite o primeiro número: "
msg2: .asciiz "Digite o segundo número: "
resultado: .asciiz "Resultado: "

.text
#Leitura do primeiro número
	li $v0, 4 #código para print
	la $a0, msg1 #argumento do print
	syscall
	
	li $v0, 5 #realizar leitura
	syscall
	
	move $s0, $v0 #Move o valor de v0 para s0
	
#Leitura do segundo número
	li $v0, 4 #código para print
	la $a0, msg2 #argumento do print
	syscall
	
	li $v0, 5 #realizar leitura
	syscall
	
	move $s1, $v0
	
	add $s2, $s0, $s1
	li $v0, 4
	la $a0, resultado
	
	syscall
	
	li $v0, 1 #Chamada de sistema para printar
	move $a0, $s2 #Move o valor da soma para a0
	syscall
	
	