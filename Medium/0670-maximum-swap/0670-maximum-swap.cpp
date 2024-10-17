class Solution {
public:
    int maximumSwap(int num) {
        string stringValue = to_string(num);
        for(int i = 0;i < stringValue.size(); i++){
            int index = i;
            for(int j = i + 1; j < stringValue.size(); j++){
                if(stringValue[index] <= stringValue[j]) index = j;
            }
            if(stringValue[i] < stringValue[index]){
                swap(stringValue[i], stringValue[index]);
                return stoi(stringValue);
            }
        }
        return num;
    }
};