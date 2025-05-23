class Solution:
    def segregateElements(self, arr):
        pos = []
        neg = []

        for i in arr:
            if i >= 0:
                pos.append(i)
            else:
                neg.append(i)

        for i in range(len(arr)):
            if i < len(pos):
                arr[i] = pos[i]
            else:
                arr[i] = neg[i - len(pos)]