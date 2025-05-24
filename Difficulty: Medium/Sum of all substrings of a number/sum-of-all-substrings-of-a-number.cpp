class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                string tmp = s.substr(i, j-i+1);
                sum += stoi(tmp);
            }
        }
        return sum;
    }
};