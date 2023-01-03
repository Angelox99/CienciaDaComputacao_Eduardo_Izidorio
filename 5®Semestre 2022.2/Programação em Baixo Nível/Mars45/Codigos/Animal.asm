.data
	msg1: .asciiz "Qual seu animal preferido? "
	msg2: .asciiz  "Meu animal preferido é "
	nome: .space 30
	
.text
	li $v0, 4
	la $a0, msg1
	syscall
	
	li $v0, 8
	la $a0, nome
	la $a1, 30
	syscall
	
	li $v0, 4
	la $a0, msg2
	syscall
	
	li $v0, 4
	la $a0, nome
	syscall