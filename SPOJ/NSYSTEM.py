total = int(input())
 
def from_MCXI(a):
  ans = 0
  letters = {'m':1000, 'c':100, 'x':10, 'i':1}
  for i in range(len(a)):
    if a[i] in letters:
      if i == 0 or a[i - 1] in letters:
        ans += letters[a[i]]
      else:
        ans += int(a[i - 1]) * letters[a[i]]
  return ans
  
def to_MCXI(a):
  ans = ''
  a = str(a)
  MCXI = ['m', 'c', 'x', 'i']
  for i in range(len(a) + 3, 3, -1):
    if a[i - 4] == '1':
      ans = MCXI[i - len(a)] + ans
    elif a[i - 4] == '0':
      continue
    else:
      ans = a[i - 4] + MCXI[i - len(a)] + ans
  return ans
 
for _ in range(total):
  MCXIs = input().split()
  print (to_MCXI(from_MCXI(MCXIs[0]) + from_MCXI(MCXIs[1])))