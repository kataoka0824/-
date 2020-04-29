import serial

def main():
	with serial.Serial('/dev/ttyACM0',9600,timeout=0.1) as ser:
		while True:
			data=ser.readline()
			print(data)
		ser.close()
		
if __name__=="__main__":
	main()
