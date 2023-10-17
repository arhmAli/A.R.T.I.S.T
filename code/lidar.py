import serial
import time
import threading

# Replace 'COMX' with your actual serial port (e.g., 'COM3' on Windows or '/dev/ttyUSB0' on Linux)
serial_port = 'COM5'

# Initialize the serial connection
ser = serial.Serial(serial_port, baudrate=115200, timeout=1)

def motor_control():
    # Start the RPLIDAR
    ser.write(b'\xA5\x60')
    time.sleep(2)  # Give it some time to start
    
    try:
        while True:
            # Control motor rotation here (e.g., send motor commands to rotate)
            # You can control the motor by sending appropriate commands to the RPLIDAR
            pass
    
    except KeyboardInterrupt:
        # Stop the motor and close the serial connection when exiting the program
        # Send the motor stop command here (e.g., ser.write(b'...'))
        ser.close()

def data_reading():
    try:
        while True:
            # Request scan data
            ser.write(b'\xA5\x20')
            time.sleep(0.01)  # Wait for data to be sent

            # Read scan data (in this example, we're just printing it)
            data = ser.read(5)
            if len(data) == 5:
                quality = data[0]
                angle = (data[1] + data[2] * 256) / 64.0
                distance = (data[3] + data[4] * 256) / 4.0
                print(f"Quality: {quality}, Angle: {angle}, Distance: {distance} cm")

    except KeyboardInterrupt:
        pass

# Create two threads: one for motor control and one for data reading
motor_thread = threading.Thread(target=motor_control)
data_thread = threading.Thread(target=data_reading)

# Start both threads
motor_thread.start()
data_thread.start()

# Wait for both threads to finish (e.g., you can use Ctrl+C to stop the program)
motor_thread.join()
data_thread.join()

# Close the serial connection (in case it's not closed properly)
ser.close()