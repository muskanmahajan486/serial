import serial
import time 
ser = serial.Serial('/dev/ttyUSB1', 115200)
data ="5"
while True:
  ser.write(data.encode()) 
  print("try")
  time.sleep(1)
  inputFile = ser.read(1)
  print(inputFile)
 
    
