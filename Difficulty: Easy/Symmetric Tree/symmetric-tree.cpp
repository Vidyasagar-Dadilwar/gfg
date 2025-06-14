/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* n1, Node* n2){
        if(!n1 && !n2)
            return true;
        if(!n1 || !n2 || n1->data != n2->data)
            return false;
        
        bool l = solve(n1->left, n2->right);
        bool r = solve(n1->right, n2->left);
        
        return l && r;
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(!root)
            return true;
        return solve(root->left, root->right);
    }
};