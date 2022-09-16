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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n<0)
            return head;
        int count=0;
        ListNode *temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(n==count){
            if(head->next){
                head=head->next;
                return head;
            }
                
            else
                return NULL;
        }
        
        int location=count-n-1;
        // cout<<count<<" "<<location;
        temp=head;
        while(location){
            temp=temp->next;
            location--;
        }
        ListNode *del=temp->next;
        temp->next=del->next;
        delete del;
        return head;
        
    }
};