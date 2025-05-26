/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
         Node* newNode = new Node(data);

        if (head == nullptr) {
            newNode->next = newNode;   
            return newNode;
        }
        
        if (data <= head->data) {
            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            tail->next = newNode;  
            newNode->next = head;  
            return newNode;        
        }

        Node* curr = head;
        while (curr->next != head && curr->next->data < data)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;

        return head; 
    }
};