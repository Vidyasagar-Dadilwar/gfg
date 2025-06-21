class Solution:
    def catchThieves(self, arr, k):
        #code  here
        cnt = 0
        i, j = 0, 0
        n = len(arr)
        
        while(i<n and j<n):
            while(i<n and arr[i]!='P'):
                i += 1
            while(j<n and arr[j]!='T'):
                j += 1
            
            if(i<n and j<n and abs(i-j) <= k):
                cnt += 1
                i += 1
                j += 1
            elif(i<n and i<j):
                i += 1
            elif(j<n and j<i):
                j += 1
        
        return cnt
            
