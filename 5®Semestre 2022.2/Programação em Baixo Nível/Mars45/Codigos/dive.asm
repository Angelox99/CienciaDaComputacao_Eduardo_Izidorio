.data
      resposta: .asciiz "A Resposta é "
      resto:  .asciiz  "  O resto é "
.text
         li $t0, 3 
         li $t1, 2    
         div $t0, $t1
         mflo $s2
         mfhi $s3
         
         
         li $v0, 4
         la $a0, resposta
         syscall 

         li $v0,1
	 move $a0, $s2
	 syscall
	 
	li $v0, 4
	la $a0, resto
	syscall
	
	li $v0,1
	move $a0, $s3
	syscall
	
	 
	
