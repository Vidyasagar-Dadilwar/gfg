/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& ans){
        if(root == NULL)
            return ;
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int> ans;
        solve(root, ans);
        if(k<1 || k > ans.size())
            return -1;
        return ans[k-1];
    }
};