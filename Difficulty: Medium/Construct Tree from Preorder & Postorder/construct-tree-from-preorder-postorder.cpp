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
};
*/

class Solution {
public:
    int findIndex(vector<int>& post, int s, int e, int x) {
        for (int i = s; i <= e; i++) {
            if (post[i] == x)
                return i;
        }
        return -1;
    }

    Node* solve(vector<int>& pre, vector<int>& post, int& ind, int s, int e) {
        if (ind >= pre.size() || s > e)
            return NULL;
        Node* root = new Node(pre[ind++]);
        if (s == e || ind >= pre.size())
            return root;

        int pos = findIndex(post, s, e, pre[ind]);
        if (pos != -1) {
            root->left = solve(pre, post, ind, s, pos);
            root->right = solve(pre, post, ind, pos + 1, e - 1);
        }

        return root;
    }

    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int ind = 0;
        return solve(pre, post, ind, 0, post.size() - 1);
    }
};