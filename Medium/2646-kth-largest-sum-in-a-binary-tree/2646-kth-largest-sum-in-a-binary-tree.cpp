class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<long long int>v;
        while(!q.empty()){
            long long int sum=0;
            long long int x=q.size();
            for(int i=0;i<x;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        return v.size()<k?-1:v[v.size()-k];
    }
};