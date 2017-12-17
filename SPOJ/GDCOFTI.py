def gcd(a, b):
  return a if b == 0 else gcd(b, a % b)
  
a = int(input());
b = int(input());
c = int(input());
 
print(gcd(a, gcd(b, c)))