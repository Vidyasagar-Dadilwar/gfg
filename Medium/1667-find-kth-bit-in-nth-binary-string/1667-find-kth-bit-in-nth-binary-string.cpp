class Solution {
private:
    string invert(string str) {
        string res = "";
        for (char ch : str) {
            if (ch == '0')
                res += '1';
            else
                res += '0';
        }
        return res;
    }

public:
    char findKthBit(int n, int k) {
        string res = "0";
        for (int i = 1; i < n; i++) {
            string inverted = invert(res);
            res += '1'; 
            reverse(inverted.begin(), inverted.end()); 
            res += inverted;
        }
        return res[k - 1]; 
    }
};