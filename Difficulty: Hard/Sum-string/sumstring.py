class Solution:
    def isSumString(self, s):
        def solve(i, j, k):
            if k == len(s):
                return True

            s1, s2 = s[i:j], s[j:k]
            if (s1.startswith('0') and len(s1) > 1) or (s2.startswith('0') and len(s2) > 1):
                return False

            num1, num2 = int(s1), int(s2)
            sum_str = str(num1 + num2)

            if s.startswith(sum_str, k):
                return solve(j, k, k + len(sum_str))
            else:
                return False

        n = len(s)
        for i in range(1, n):
            for j in range(i + 1, n):
                if solve(0, i, j):
                    return True
        return False