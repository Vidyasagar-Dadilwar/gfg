class Solution {
public:
    bool validgroup(vector<int>& arr, int k) {
        int n = arr.size();
        if (n % k != 0) 
            return false;

        map<int, int> count;
        for (int num : arr) 
            count[num]++;

        for (auto it = count.begin(); it != count.end(); ++it) {
            int start = it->first, freq = it->second;
            if (freq == 0) 
                continue;

            for (int i = 0; i < k; ++i) {
                int val = start + i;
                if (count[val] < freq) 
                    return false;
                count[val] -= freq;
            }
        }
        return true;
    }
};
