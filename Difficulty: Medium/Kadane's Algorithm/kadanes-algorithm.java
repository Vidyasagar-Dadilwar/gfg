class Solution {
    int maxSubarraySum(int[] arr) {
        // Your code here
        int sum = 0, maxi = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++){
            if(sum < 0){
                sum = 0;
            }
            sum += arr[i];
            maxi = Math.max(maxi, sum);
        }
        return maxi;
    }
}
