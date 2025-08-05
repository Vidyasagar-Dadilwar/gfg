class Solution {
  public:
    bool isPalinSent(string &s) {
        vector<char> arr;
        for (char i : s) {
            if (isalnum(i))
                arr.push_back(tolower(i));
        }
        int n = arr.size();
        for (int i = 0; i < n / 2; i++) {
            if (arr[i] != arr[n - i - 1])
                return false;
        }
        return true;
    }
};