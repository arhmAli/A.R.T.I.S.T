<!DOCTYPE html>
<html>

<body>
    <h1>Setting Up Laptop to Send Data to the Microcontroller</h1>
    <h2>Step 1: Create the boot.py File</h2>
    <p>Create the <code>boot.py</code> file in the MicroPython, which essentially connects to the Wi-Fi network.</p>
    <h2>Step 2: Create the Server</h2>
    <p>Create the server in the MicroPython, which will accept the data sent to it.</p>
    <h3>i) Define a Host and Port</h3>
    <p>Define the host and port for your server.</p>
    <h3>ii) Make a Socket Connection</h3>
    <p>Make a socket connection using:</p>
    <pre><code>socket.socket(socket.AF_INET, socket.SOCK_STREAM)</code></pre>
    <h3>iii) Bind the Socket</h3>
    <p>Bind the socket to listen to the host and port.</p>
    <h3>iv) Listen for Connections</h3>
    <p>Listen for one connection at a time using:</p>
    <pre><code>server.listen(1)</code></pre>
    <h3>v) Receive and Process Data</h3>
    <p>Make a loop in which you wait for a connection:</p>
    <pre><code>
while True:
    client_socket, client_address = server.accept()
    data = client_socket.recv(1024)
    print(f"data: {data.decode('utf-8')}")
    client_socket.close()
</code></pre>
</body>

</html>
