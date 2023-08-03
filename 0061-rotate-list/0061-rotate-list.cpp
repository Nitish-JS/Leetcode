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
        if(!head || !head->next)
            return head;
        ListNode* last=head;
        int n=1;
        while(last && last->next){
            n++;
            last=last->next;
        }
        last->next=head;
        k=k%n;
        last=head;
        for(int i=0;i<n-k-1;i++){
            last=last->next;
        }
        head=last->next;
        last->next=NULL;
        return head;
        
        
    }
};