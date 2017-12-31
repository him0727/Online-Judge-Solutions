t = int(input())
i = 1
while t > 0:
  t -= 1
  a, b, c =[int(x) for x in input().split()]
  bb = int(b * (b + 1) / 2)
  cc = int(c * (c + 1) / 2)
  print("Case {}: {}".format(i, a * bb * cc))
  i += 1