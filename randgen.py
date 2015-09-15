import random

f_out = open('random.bin', 'wb')
data = [ random.randint(0,255) for a in range(512) ]
data = bytearray(data)
f_out.write(data)
f_out.close()
