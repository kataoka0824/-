import serial
import time

 
ser = serial.Serial('/dev/ttyACM0', 9600)

for i in range(10):
        #ser.write('u'.encode('utf-8'))
        ser.write(b'u')
        time.sleep(0.5)
        #ser.write('d'.encode('utf-8'))
        ser.write(b'd')
        time.sleep(0.5)
ser.close()
