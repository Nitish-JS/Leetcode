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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *last=head;
        if(!head || !head->next)
            return head;
        int n=1;
        while(last->next){
            n++;
            // if(last->next)
            last=last->next;
        }
        last->next=head;
        last=head;
        k=k%n;
        for(int i=0;i<n-k-1;i++){
            last=last->next;
            // prev->next=NULL;
        }
        head=last->next;
        last->next=NULL;
        
        return head;
        
    }
};