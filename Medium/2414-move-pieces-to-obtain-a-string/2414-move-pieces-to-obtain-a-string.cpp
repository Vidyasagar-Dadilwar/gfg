class Solution {
public:
    bool canChange(string start, string target) {
        string s;
        string t;
        for(auto c:start){
            if(c!='_'){
                s+=c;
            }
        }
         for(auto c:target){
            if(c!='_'){
                t+=c;
            }
        }
        if(s!=t) return false;
        int i=0;
        int j=0;
        while(i<start.size() && j < target.size()){
            while(start[i]=='_') i++;
            while(target[j]=='_')j++;
            if(i==start.size() || j==target.size()) break;
            if(start[i]!=target[j]) return false;
            if(start[i]=='L' && i<j) return false;
            if(start[i]=='R' && i>j) return false;
            i++;
            j++;
            
        }
        return true;
    }
};