import serial

port = '/dev/rfcomm0'
baudrate = 57600

ser = serial.Serial(port, baudrate)

try:
    while True:
        data = ser.readline()
        if data:
            print("Reçu :", data.decode('utf-8'))
except KeyboardInterrupt:
    pass
finally:
    ser.close()
    print("Connexion fermée")
