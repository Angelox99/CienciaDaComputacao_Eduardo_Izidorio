.data
msg: .asciiz "ola, mundo"

.text

li $v0,4
la $a0, msg
syscall 