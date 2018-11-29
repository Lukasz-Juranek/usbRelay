import serial
# before start 
# 1. pip install pyserial  
# 2. sudo chmod 666 /dev/ttyS6

ser = serial.Serial('/dev/ttyS9')  

#print(ser.name)         
#ser.write(b'R0D800,S1P5000,S0P2000\r')
#print (ser.readline())
#ser.write(b'R1D200,S1P1000,S0P1000\r')  
#print (ser.readline())
#for x in range(8):
#    ser.write(b'R'+str(x)+',S1P'+str((x+1)*1000)+',S0P'+str((x+1)*1000)+'\r')
for x in range(8):
    ser.write(b'R'+str(x)+',S1P1000'+',S0P1000'+'\r')
    print (ser.readline()) 
ser.write(b'SC\r')
print (ser.readline())   
ser.close()             
