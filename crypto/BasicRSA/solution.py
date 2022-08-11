#!/usr/bin/env python3
#from Crypto.Util.number import inverse
from Crypto.Util.number import long_to_bytes

def egcd(a,b):
	if a==0:
		return(b,0,1)
	else:
		g , y , x = egcd(b%a,a)
		return (g,x-(b//a)*y,y)
def modinv(a,m):
	g , x , y = egcd(a,m)
	if g!=1 :
		raise Exception('modular inverse does not exist')
	else:
		return x%m
e = 65537
c = 
p = 
q = 
n = 
totient = (p-1)*(q-1)
d = modinv(e,totient)
plain = pow(c,d,n)
#print(hex(plain))
#print(bytearray.fromhex(hex(plain)[2:]).decode())
print(long_to_bytes(plain))
