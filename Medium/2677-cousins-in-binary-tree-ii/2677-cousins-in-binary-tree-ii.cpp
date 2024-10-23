/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode* , TreeNode*>>q;
        unordered_map<TreeNode*, int>mp;
        q.push({root, NULL});
        int sum = 0;
        while(!q.empty()){
            int temp = 0;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                if(parent){
                    curr->val = sum - mp[parent];
                }
                if(curr->left){
                    q.push({curr->left, curr});
                    mp[curr] = curr->left->val;
                    temp += curr->left->val;
                }
                if(curr->right){
                    q.push({curr->right, curr});
                    mp[curr] += curr->right->val;
                    temp += curr->right->val;
                }
            }
            sum = temp;
        }
        root->val = 0;
        return root;
    }
};