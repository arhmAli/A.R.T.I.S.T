import serial
import time
serial_port = 'COM5'
ser = serial.Serial(serial_port, baudrate=115200, timeout=1)
ser.write(b'\xA5\x20')
time.sleep(2)  #  Time to start
try:
    while True:
        # Request scan data
        ser.write(b'\xA5\x20')
        time.sleep(0.01)  # Wait for data to be sent
        data = ser.read(5)
        if len(data) == 5:
            quality = data[0]
            angle = (data[1] + data[2] * 256) / 64.0
            distance = (data[3] + data[4] * 256) / 4.
            # delay for 1 sec each set of values
            time.sleep(1)
            print(f"Quality: {quality}, Angle: {angle}, Distance: {distance} cm")
            print(data)

except KeyboardInterrupt:
    ser.close()
