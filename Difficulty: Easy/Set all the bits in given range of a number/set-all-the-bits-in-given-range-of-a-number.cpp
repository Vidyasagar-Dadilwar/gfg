class Solution {
  public:
    int setAllRangeBits(int N, int L, int R) {
        // code here
        int x = (1<<R) - 1, y = (~0) << (L-1);
        return N | (x&y);
    }
};