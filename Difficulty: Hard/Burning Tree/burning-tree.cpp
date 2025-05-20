//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* bfsToParent(Node* root, int target, map<Node*, Node*>& mp){
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        while(!q.empty()){
            auto node = q.front();
            if(node->data == target)
                res = node;
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int bfs(Node* node, map<Node*, Node*>& mp){
        queue<Node*> q;
        q.push(node);
        
        map<Node*, int> vis;
        vis[node] = 1;
        
        int dist = 0;
        
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            for(int i=0; i<sz; i++){
                auto n = q.front();
                q.pop();
                if(n->left && !vis[n->left]){
                    flag = 1;
                    vis[n->left] = 1;
                    q.push(n->left);
                }
                if(n->right && !vis[n->right]){
                    flag = 1;
                    vis[n->right] = 1;
                    q.push(n->right);
                }
                if(mp.find(n) != mp.end() && !vis[mp[n]]){
                    flag = 1;
                    vis[mp[n]] = 1;
                    q.push(mp[n]);
                }
            }
            if(flag)
                dist++;
        }
        return dist;
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> mp;
        Node* node = bfsToParent(root, target, mp);
        int timer = bfs(node, mp);
        return timer;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends