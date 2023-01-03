#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#cliente
import socket 
IP_Servidor = '192.168.0.1'
#Endereço IP do Servidor

PORTA_Servidor = 6000
#Porta em que o servidor estara ouvindo

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#socket.SOCK_DGRAM=usaremos udp

DESTINO = (IP_Servidor, PORTA_Servidor)
#destino(IP + porta) do Servidor

Mensagem = input()
#Mensagem recebera dados do teclado

udp.sendto(bytes(Mensagem,"utf8"), DESTINO)
#enviar a mensagem para o destino(IP +porta)
#bvtes(Mensagem,"utf8") = converte tipo str para byte

udp.close()
# fim socket


# %%
