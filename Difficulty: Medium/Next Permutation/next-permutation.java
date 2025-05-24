// User function Template for Java

class Solution {
    void nextPermutation(int[] nums) {
        // code here
        int n = nums.length;
        int i = n - 2;
    
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
    
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        int s = i+1, e = n-1;
        while (s < e) {
            int t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;
            s++;
            e--;
        }
    }
}