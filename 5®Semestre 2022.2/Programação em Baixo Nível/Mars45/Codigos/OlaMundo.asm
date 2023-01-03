.data
msg: .asciiz "Olá Mundo!" #(isso é um comentário) mensagem exibida para o usuário.

.text
li $v0, 4 #Instrução para mpressão de String
la $a0, msg #indicar o endereço em que está a mensagem
syscall #façca! imprima...
