.data
	caractere: .byte 'C'

.text
	li $v0, 4
	la $a0, caractere
	syscall
