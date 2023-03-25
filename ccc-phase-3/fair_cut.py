n, k = map(int, input().split())

if 2*k > n:
    k = n - k

a = sorted(map(int, input().split()))

# create dp

dp = [[float('inf') for i in range(0, n + 1)] for j in range(0, n + 1)]

dp[0][0] = 0

for i in range(0, n):
    for j in range(0, i + 1):
        if i > k and i-j > n-k:
            continue
        to_li = dp[i][j] + a[i] * (i - j - (n - k - (i - j)))
        to_lu = dp[i][j] + a[i] * (j - (k - j))
        # to Li
        if dp[i+1][j+1] > to_li:
            dp[i+1][j+1] = to_li
        
        # to Lu
        if dp[i+1][j] > to_lu:
            dp[i+1][j] = to_lu

print(dp[n][k])