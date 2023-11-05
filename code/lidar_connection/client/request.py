import socket
import json
microcontroller_host = '192.168.10.11'
microcontroller_port = 5000  # Use the same port as in the MicroPython code

# Create a socket client
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((microcontroller_host, microcontroller_port))

lidar_data = [
    {
        "X-coordinate": 4.56,
        "Y-coordinate": 2.34,
        "Z-coordinate": 1.20,
        "Intensity": 120
    },
    {
        "X-coordinate": 5.12,
        "Y-coordinate": 3.10,
        "Z-coordinate": 0.98,
        "Intensity": 105
    },
    {
        "X-coordinate": 4.80,
        "Y-coordinate": 2.75,
        "Z-coordinate": 1.15,
        "Intensity": 92
    },
    {
        "X-coordinate": 6.25,
        "Y-coordinate": 1.90,
        "Z-coordinate": 0.75,
        "Intensity": 140
    },
    {
        "X-coordinate": 3.90,
        "Y-coordinate": 3.40,
        "Z-coordinate": 1.05,
        "Intensity": 115
    }
]

for i, point in enumerate(lidar_data, start=1):
    print(f"Point {i}: {point}")

sensor_data = json.dumps(lidar_data)

client.send(sensor_data.encode('utf-8'))
client.close()
