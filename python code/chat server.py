import socket

HOST = '192.168.54.249'                 # Symbolic name meaning all available interfaces
PORT = 50001              # Arbitrary non-privileged port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()
print 'Connected by', addr
while 1:
    data = conn.recv(1024)
    if not data: break
    conn.sendall(data + 'popo')
conn.close()