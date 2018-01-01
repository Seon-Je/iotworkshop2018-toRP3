import serial
ser = serial.Serial('/dev/ttyACM0',9600)

while True:
	value = ser.readline().strip()
	value = value.decode('utf-8')
	print(value)