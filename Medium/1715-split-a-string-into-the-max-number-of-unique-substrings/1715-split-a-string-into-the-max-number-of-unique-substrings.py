class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        
        def splits(index,hashset):
            nonlocal n
            if index == n:
                res.append(len(hashset))
                return
            
            for i in range(index,n):
                substring = s[index:i+1]
                if substring in hashset:
                    continue
                hashset.add(substring)
                splits(i+1,hashset)
                hashset.remove(substring)

            

        n = len(s)
        res = []
        splits(0,set())
        return max(res)
        