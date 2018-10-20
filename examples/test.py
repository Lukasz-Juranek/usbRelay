import serial
# before start 
# 1. pip install pyserial  
# 2. sudo chmod 666 /dev/ttyS9

ser = serial.Serial('/dev/ttyS9')  

#print(ser.name)         
#ser.write(b'R7D800,S1P5000,S0P2000\r')
#print (ser.readline())
#ser.write(b'R6D200,S1P1000,S0P1000\r')  
#print (ser.readline())
for x in range(8):
    ser.write(b'R'+str(x)+',S1P1000,S0P2000\r')
    print (ser.readline()) 
ser.write(b'SC\r')
print (ser.readline())   
ser.close()             