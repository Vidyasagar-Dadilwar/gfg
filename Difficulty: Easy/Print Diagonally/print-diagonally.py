#User function Template for python3

def downwardDiagonal(N, A): 
    # code here 
    ans = []
    for length in range(1, 2 * N):  # Loop through all diagonals
        i, j = 0, length - 1
        if length >= N:
            i = length % N
            j = N - 1
        while j >= 0 and i < N:
            ans.append(A[i][j])
            i += 1
            j -= 1
    return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        matrix =[]
        for i in range(n):
            row = list(map(int, input().strip().split()))
            matrix.append(row)
        ans = downwardDiagonal(n,matrix)
        for i in ans:
            print(i,end=" ")
        print()

        print("~")
# } Driver Code Ends