total = int(input())

for i in range(total):
  nums = input().split()
  def reverse(num):
    num = list(num)
    a = 0
    b = len(num) - 1
    while a < b:
      num[a], num[b] = num[b], num[a]
      a += 1
      b -= 1
    return int(''.join(num))
  num1 = reverse(nums[0])
  num2 = reverse(nums[1])
  print (reverse(str(num1 + num2)))