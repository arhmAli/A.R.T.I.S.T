import socket

host = '0.0.0.0'  
port = 5000  
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(1)  # Listen for one connection at a time
while True:
    print("Waiting for a connection...")
    client_socket, client_address = server.accept()
    print(f"Accepted connection from {client_address}")
    data = client_socket.recv(1024)
    print(f"Received data: {data.decode('utf-8')}")
    client_socket.close()

