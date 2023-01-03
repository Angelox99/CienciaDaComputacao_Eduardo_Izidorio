#!/usr/bin/env python
# coding: utf-8

# In[ ]:



#servidor
import socket
MEU_IP = ''
# endereço IP do servidor, '' = significa que ouvira em todas as interfaces

Minha_Porta = 6000
#porta que o servidor vai ouvir

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#socket.SOCK DGRAM = usaremos udp

MEU_SERVIDOR = (MEU_IP, Minha_Porta)
udp.bind(MEU_SERVIDOR)

#faz o bind do ip e a porta para que possa começar a ouvir

Mensagem_Recebida,END_cliente = udp.recvfrom(1024)

# socket.recvfrom(bufsize[, flags]) deve ser uma potencia de 2
#Recebe dados do soquete = um par (string, endereça) onde string eh uma string representado os dados recebidos
print ("recebido = ",Mensagem_Recebida,", Do cliente", END_cliente)
# endereco eh o endereco do soket que enviou os dados
udp.close()
#fim do socket 


# In[ ]:





# In[ ]:




