/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void inorder(Node*root, vector<int>& ans){
        if(!root)
            return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        vector<int> v;
        inorder(root, v);
        auto it = upper_bound(v.begin(), v.end(), k);

        if (it != v.begin()) {
            --it;
            return *it;
        } 
        else {
            return -1;
        }
    }
};