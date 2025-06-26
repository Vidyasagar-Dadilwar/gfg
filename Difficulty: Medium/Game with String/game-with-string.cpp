class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char, int> freq;
        for (char ch : s) 
            freq[ch]++;
    
        priority_queue<int> maxHeap;
        for (auto& it : freq) 
            maxHeap.push(it.second);
    
        while (k-- && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            if (top > 1) 
                maxHeap.push(top - 1);
        }
        int res = 0;
        while (!maxHeap.empty()) {
            res += maxHeap.top() * maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};