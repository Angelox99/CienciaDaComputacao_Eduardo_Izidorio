import socket
sock=socket.socket(socket.AF_NET,socket.SOCK_DGRAM)
sock.bind(('127.0.0.1',12345))

print("Servidor UDP escutando")

while True;
    data,addr=sock.recvfrom(1024)
    print(str(data, encoding='utf-8'))
    message=byte