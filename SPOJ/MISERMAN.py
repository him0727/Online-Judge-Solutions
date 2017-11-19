size = input().split()
n = int(size[0])
m = int(size[1])
 
source = [[None] * (m + 2) for _ in range(n + 2)]
dp = [[None] * (m + 2) for _ in range(n + 2)]
 
for i in range(1, n + 1):
  data = input().split()
  for j in range(1, m + 1):
    source[i][j] = int(data[j - 1])
 
for i in range(1, m + 1):
  dp[n][i] = source[n][i]
 
for i in range(n - 1, 0, -1):
  for j in range(1, m + 1):
    dp[i][j] = source[i][j] + dp[i + 1][j]
    if j > 1: dp[i][j] = min(dp[i][j], source[i][j] + dp[i + 1][j - 1])
    if j < m: dp[i][j] = min(dp[i][j], source[i][j] + dp[i + 1][j + 1])
 
print (min(dp[1][1:m + 1]))
