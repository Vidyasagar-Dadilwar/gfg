# cook your dish here
MOD = 10**9 + 7
def solve(x):
    divii = 0
    for i in range(1, int(x**0.5) + 1):
        if x % i == 0:
            if i * i == x:
                divii += 1  
            else:
                divii += 2  
    return divii
    
def factt(M):
    fact = 1
    for i in range(2, M + 1):
        fact = (fact * i) % MOD
    return fact

N, M = map(int, input().split())
A = list(map(int, input().split()))
res = factt(M)
ans = []
for a in A:
    B_i = (a * res) % MOD
    divii = solve(B_i)
    ans.append(divii)
print(" ".join(map(str, ans)))