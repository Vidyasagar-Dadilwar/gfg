class Solution:
    def checkString(self, s: str) -> bool:
        a=-1
        b=-1
        flag = True
        for i in range(len(s)):
            if(s[i] == 'a'):
                a=i
            elif(s[i] == 'b' and flag):
                flag = False
                b=i
        if(b==-1 or a==-1):
            return True
        return a<b