// User function Template for Java

class Solution {
    public int longestSubarray(int[] a, int k) {
        // code here
        int len = 0, s = 0, n = a.length;
        HashMap<Integer, Integer> preSum = new HashMap<>();

        for (int i = 0; i < n; i++) {
            s += a[i];

            if (s == k) {
                len = Math.max(len, i + 1);
            }

            int x = s - k;
            if (preSum.containsKey(x)) {
                len = Math.max(len, i - preSum.get(x));
            }

            if (!preSum.containsKey(s)) {
                preSum.put(s, i);
            }
        }
        return len;
    }
}
