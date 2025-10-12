/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int ans = 0;
    int solve(Node* node){
        if(!node)   return 0;
        int l = solve(node->left);
        int r = solve(node->right);
        ans += abs(l) + abs(r);
        return node->data + l + r -1;
    }
    int distCandy(Node* root){
        solve(root);
        return ans;
    }
};