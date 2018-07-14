n = int(input())
f = [0] * 10010
f[1] = 2
f[2] = 3
for i in range(3, 10001):
  f[i] = f[i - 1] + f[i - 2]
print(f[n])