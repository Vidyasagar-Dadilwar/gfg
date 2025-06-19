class Solution {
  public:
    string caseSort(string& s) {
        vector<char> u, l;
        for(auto i: s){
            if(isupper(i))
                u.push_back(i);
            else
                l.push_back(i);
        }
        sort(u.begin(), u.end());
        sort(l.begin(), l.end());
        string ans = "";
        int j=0, k=0;
        for(auto i: s){
            if(isupper(i))
                ans += u[j++];
            else
                ans += l[k++];
        }
        return ans;
    }
};