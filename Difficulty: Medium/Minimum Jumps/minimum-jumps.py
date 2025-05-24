class Solution:
	def minJumps(self, arr):
	    # code here
	    n = len(arr)
        maxi = 0
        curr = 0
        jump = 0
        
        if(n == 0):
            return 0
        
        if(arr[0] == 0):
            return -1
            
        for i in range(len(arr)):
            maxi = max(maxi, i+arr[i])
            
            if(maxi >= n-1):
                return jump+1
            
            if(i == curr):
                if(curr == maxi):
                    return -1
                else:
                    jump += 1
                    curr = maxi
        return jump