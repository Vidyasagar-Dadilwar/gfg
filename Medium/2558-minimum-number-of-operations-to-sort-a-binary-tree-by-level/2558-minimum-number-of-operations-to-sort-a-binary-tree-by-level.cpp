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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> a1, a2;
        int cnt = 0;

        while (!q.empty()) {
            int n = q.size();
            a1.clear();
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                a1.push_back(temp->val);
            }
            a2 = a1;
            sort(a2.begin(), a2.end());
            int i = 0;
            while (i < a1.size()) {
                if (a1[i] == a2[i]) {
                    i++;
                    continue;
                } 
                else {
                    int j = lower_bound(a2.begin(), a2.end(), a1[i]) - a2.begin();
                    swap(a1[i], a1[j]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};