class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        l=list(sentence.split(' '))
        j=0 
        k=0
        for i in l:
            if i.startswith(searchWord):
                return l.index(i)+1
        return -1