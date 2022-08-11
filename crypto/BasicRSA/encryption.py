from Crypto.Util.number import bytes_to_long, long_to_bytes, getPrime
 
p       = getPrime(100)      
q       = getPrime(100)      
N       = p*q                 
totient = (p-1)*(q-1)         
e       = 65537               
d       = pow(e, -1, totient) 
message = b""  
message = bytes_to_long(message) 
ciphertext = pow(message, e, N) 
print("ciphertext")
print("N")
