#include <bits/stdc++.h>
using namespace std;
/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap based on node value
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Push all head nodes into heap
        for(auto it: arr) {
            if(it) pq.push(it);
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while(!pq.empty()) {
            Node* top = pq.top();
            pq.pop();

            tail->next = top;
            tail = tail->next;

            if(top->next) pq.push(top->next);
        }

        return dummy->next;
    }
};