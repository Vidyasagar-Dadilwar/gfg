class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // brute force
        // for(int i=0; i<nums.length; i++){
        //     for(int j=i+1; j<nums.length;j++){
        //         if(Math.abs(i-j) <= k){
        //             if(nums[i] == nums[j])
        //                 return true;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return false;



        // optimal (map)
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            if(mp.containsKey(nums[i]) && (i-mp.get(nums[i]) <= k))
                return true;
            mp.put(nums[i],i);
        }   
        return false;
    }
}