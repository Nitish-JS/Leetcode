/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // space complexity O(n)
        unordered_map<Node*,Node*> um;
        Node* temp=head;
        while(temp){
            um[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            um[temp]->next=um[temp->next];
            um[temp]->random=um[temp->random];
            temp=temp->next;
        }
        return um[head];
        
       
        
    }
};