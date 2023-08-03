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
        // unordered_map<Node*,Node*> um;
        // Node* temp=head;
        // while(temp){
        //     um[temp]=new Node(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     um[temp]->next=um[temp->next];
        //     um[temp]->random=um[temp->random];
        //     temp=temp->next;
        // }
        // return um[head];
        
        // space complexity O(1)
        
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp && temp->next){
            if(temp->random==NULL)
                temp->next->random=NULL;
            else
                temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node* deepCopy=new Node(0);
        Node* copy=deepCopy;
        temp=head;
        while(temp){
            Node* front=temp->next->next;
            copy->next=temp->next;
            temp->next=front;
            copy=copy->next;
            temp=temp->next;
            
        }
        return deepCopy->next;
        
    }
};