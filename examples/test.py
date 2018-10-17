import serial

ser = serial.Serial('/dev/ttyS13')  
print(ser.name)         
ser.write(b'R7D800,S1P5000,S0P2000\r')
print (ser.readline())
ser.write(b'R6D200,S1P1000,S0P1000\r')  
print (ser.readline())
ser.write(b'R5,S1P0\r')
print (ser.readline())   
ser.close()             