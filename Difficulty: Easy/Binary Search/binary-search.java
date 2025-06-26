class Solution {
    public int binarysearch(int[] nums, int target) {
        int low = 0, high = nums.length;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // At this point, `low` is the lower bound index
        if (low < nums.length && nums[low] == target) {
            return low; // Target found at lower bound
        }

        return -1; // Target not found
    }
}
