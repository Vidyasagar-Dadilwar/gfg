/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *t1 = head, *t2 = head;
        if(head == NULL)
            return head;
        
        while(t1 != NULL){
            t1 = t1->next;
            n++;
        }
        n = n-k;

        t1 = head;
        for(int i=1; i<k; i++){
            t1 = t1->next;
        }
        for(int i=1; i<=n; i++){
            t2 = t2->next;
        }
        swap(t1->val, t2->val);
        return head;
    }
};