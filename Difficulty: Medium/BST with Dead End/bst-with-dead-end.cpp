/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node* root, vector<int>& ans){
        if(!root)
            return false;
        if(!root->left && !root->right){
            bool t1=false, t2=false;
            if(root->data - 1 > 0)
                t1 = binary_search(ans.begin(), ans.end(), root->data-1);
            else
                t1 = true;
            t2 = binary_search(ans.begin(), ans.end(), root->data+1);
            return t1 && t2;
        }
        return solve(root->left, ans) || solve(root->right, ans);
    }
    void inorder(Node* root, vector<int>& ans){
        if(!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        vector<int> ans;
        inorder(root, ans);
        return solve(root, ans);
    }
};