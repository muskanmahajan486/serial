import serial
ser = serial.Serial('/dev/ttyACM0', 115200)
data = "1"
while True:
    ser.write(data.encode()) 
    inputFile = ser.read(1)
    print(inputFile)
    
