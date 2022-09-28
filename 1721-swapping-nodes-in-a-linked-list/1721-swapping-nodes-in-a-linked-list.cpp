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
        ListNode *slow=head,*fast=head,*kth=NULL;
        k--;
        while(k--){
            fast=fast->next;
        }
        kth=fast;
        fast=fast->next;
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        swap(kth->val,slow->val);
        return head;
    }
};