class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        double med;
        sort(nums1.begin(),nums1.end());
        if (nums1.size() % 2 != 0) {
            med = (double)nums1[nums1.size() / 2];
        } else {
            med = (double)(nums1[(nums1.size() - 1) / 2] + nums1[nums1.size() / 2]) / 2.0;
        }
        return med;
    }
};